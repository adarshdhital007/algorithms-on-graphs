#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

bool bfs(int start, vector<vector<int>> &adj, vector<int>&colors)
{
  queue<int> q;
  q.push(start);
  colors[start] = 0;
  
  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int neighbor : adj[node])
    {
      if (colors[neighbor] == -1)
      {
        colors[neighbor] = 1 - colors[node];
        q.push(neighbor);
      }
      else if (colors[neighbor] == colors[node])
      {
        return false;
      }
    }
  }
  return true;
}
int bipartite(vector<vector<int>> &adj)
{
  int n = adj.size();
  vector<int> colors(n, -1);

  for (int i = 0; i < n; i++)
  {
    if (colors[i] == -1)
    {
      if (!bfs(i, adj, colors))
      {
        return 0;
      }
    }
  }
  return 1;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
