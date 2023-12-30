#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

vector<vector<p>> createAdjacencyList(int n, vector<vector<int>> &edges)
{
  vector<vector<p>> adj(n);

  for (auto &[src, dest, weight] : edges)
  {
    adj[src].push_back({dest, weight});
    adj[dest].push_back({src, weight});
  }

  return adj;
}

vector<int> dijkstras(int n, int src, vector<vector<int>> &edges)
{
  vector<int> dist(n, INT_MAX);
  priority_queue<p, vector<p>, greater<p>> minHeap;
  vector<vector<p>> adj = createAdjacencyList(n, edges);

  dist[src] = 0;
  minHeap.push({0, src});

  while (!minHeap.empty())
  {
    auto [dist, node] = minHeap.top();

    for (auto &[neighbour, edgeCost] : adj[node])
    {
      if (dist[node] + edgeCost < dist[neighbour])
      {
        dist[neighbour] = dist[node] + edgeCost;
        minHeap.push({dist[neighbour], neighbour});
      }
    }
  }
}

int main()
{
  vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 3}};
  int src = 0;
  int n = 3;

  vector<int> dist = dijkstras(n, src, edges);

  for (auto &i : dist)
    cout << i << " ";

  return 0;
}