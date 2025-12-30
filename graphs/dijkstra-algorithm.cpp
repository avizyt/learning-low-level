#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int source, int n, vector<vector<pii>> &adj) {
  // distance[i] stores the shortest distance from source to i
  vector<int> dist(n, INT_MAX);
  dist[source] = 0;

  // min -heap to store {distace, node}
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, source});

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;

    pq.pop();

    // if we found a longer path already in the queue, skip it
    if (d > dist[u])
      continue;

    // relax neighbors
    for (auto &edge : adj[u]) {
      int v = edge.first;
      int weight = edge.second;

      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << "Node " << i << " Distance: " << dist[i] << endl;
  }
}

int main() {
  // Number of nodes in the graph
  int n = 5;

  // Adjacency list: adj[u] contains list of {neighbor, weight}
  vector<vector<pii>> adj(n);

  // Adding edges (Building a sample graph)
  // Edge: node 0 -> node 1 (weight 10), node 0 -> node 4 (weight 5)
  adj[0].push_back({1, 10});
  adj[0].push_back({4, 5});

  adj[1].push_back({2, 1});
  adj[1].push_back({4, 2});

  adj[2].push_back({3, 4});

  adj[3].push_back({2, 6});
  adj[3].push_back({0, 7});

  adj[4].push_back({1, 3});
  adj[4].push_back({2, 9});
  adj[4].push_back({3, 2});

  // Run Dijkstra's starting from node 0
  dijkstra(0, n, adj);

  return 0;
}
