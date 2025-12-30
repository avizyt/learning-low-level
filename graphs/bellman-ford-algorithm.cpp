#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int src, dest, weight;
};

void bellmanFord(int V, int E, int src, vector<Edge> &edges) {
  // Step 1: Initialize distances from src to all other vertices as infinite
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;

  // Step 2: Relax all edges |V -1 times
  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
      int u = edges[j].src;
      int v = edges[j].dest;

      int weight = edges[j].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  // Step 3: Check for negative-weight cycles
  // If we can still relax an edge, than a negative cycle exists
  for (int i = 0; i < E; i++) {
    int u = edges[i].src;
    int v = edges[i].dest;
    int weight = edges[i].weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
      cout << "Graph contains a negative weight cycle!" << endl;
      return;
    }
  }

  cout << "Vertex distance from source:" << endl;
  for (int i = 0; i < V; i++) {
    cout << i << "\t\t" << dist[i] << endl;
  }
}

int main() {
  int V = 5; // Total vertices
  int E = 8; // Total edges
  vector<Edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
                        {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

  bellmanFord(V, E, 0, edges);
  return 0;
}
