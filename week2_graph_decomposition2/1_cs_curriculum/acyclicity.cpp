#include <iostream>
#include <vector>

using std::pair;
using std::vector;

bool dfs(vector<vector<int>> &adj, int node, vector<bool> &visited, vector<bool> &recStack)
{
  if (recStack[node])
    return true;
  if (visited[node])
    return false;

  visited[node] = true;
  recStack[node] = true;

  for (int neighbor : adj[node])
  {
    if (dfs(adj, neighbor, visited, recStack))
      return true;
  }

  recStack[node] = false;
  return false;
}

int acyclic(vector<vector<int>> &adj)
{
  vector<bool> visited(adj.size(), false);
  vector<bool> recStack(adj.size(), false);

  for (int i = 0; i < adj.size(); i++)
  {
    if (!visited[i])
    {
      if (dfs(adj, i, visited, recStack))
        return 1;
    }
  }

  return 0;
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
