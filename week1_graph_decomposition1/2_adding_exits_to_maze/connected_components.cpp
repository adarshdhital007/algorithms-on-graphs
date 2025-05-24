#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int v)
{
  visited[v] = true;

  for (int neighbor : adj[v])
  {
    if (!visited[neighbor])
    {
      dfs(adj, visited, neighbor);
    }
  }
}

int number_of_components(vector<vector<int>> &adj)
{
  vector<bool> visited(adj.size());
  int count = 0;

  for (int i = 0; i < adj.size(); i++)
  {
    if (!visited[i])
    {
      dfs(adj, visited, i);
      count++;
    }
  }
  return count;
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
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
