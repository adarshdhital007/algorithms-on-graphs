#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

int distance(vector<vector<int>> &adj, int s, int t)
{
  int n = adj.size();

  queue<int> q;
  vector<int> dist(n, -1);

  dist[s] = 0;
  q.push(s);

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int neighbor : adj[node])
    {
      if (dist[neighbor] == -1)
      {
        dist[neighbor] = dist[node] + 1;
        q.push(neighbor);

        if (neighbor == t)
        {
          return dist[t];
        }
      }
    }
  }
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
