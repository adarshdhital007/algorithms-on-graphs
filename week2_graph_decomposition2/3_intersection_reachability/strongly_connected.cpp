#include <algorithm>
#include <iostream>
#include <vector>

using std::pair;
using std::vector;

// we need two dfs for kosaraju's algorithm, if we want a single pass solution we need to use Tarjan's algo which is a bit complex.
void dfs1(vector<vector<int>> &adj, int node, vector<bool> &visited, vector<int> &order)
{
  visited[node] = true;

  for (int neighbor : adj[node])
  {
    if (!visited[neighbor])
    {
      dfs1(adj, neighbor, visited, order);
    }
  }
  order.push_back(node);
}

void dfs2(vector<vector<int>> &adj, int node, vector<bool> &visited)
{
  visited[node] = true;

  for (int neighbor : adj[node])
  {
    if (!visited[neighbor])
    {
      dfs2(adj, neighbor, visited);
    }
  }
}
int number_of_strongly_connected_components(vector<vector<int>> adj)
{
  int n = adj.size();
  vector<bool> visited(n, false);
  vector<int> order;
  // write your code here
  for (int i = 0; i < adj.size(); i++)
  {
    if (!visited[i])
    {
      dfs1(adj, i, visited, order);
    }
  }

  vector<vector<int>> rev(n);
  for (int i = 0; i < n; i++)
  {
    for (int neighbor : adj[i])
    {
      rev[neighbor].push_back(i);
    }
  }

  fill(visited.begin(), visited.end(), false);
  int result = 0;
  reverse(order.begin(), order.end());

  for (int node : order)
  {
    if (!visited[node])
    {
      dfs2(rev, node, visited);
      result++;
    }
  }

  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
