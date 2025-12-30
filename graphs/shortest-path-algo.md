# Shortest Path Finding Algorithm

## Dijkstra's Algorithm

Dijkstra's Algorithm is a classic "greedy" algorithm used in graph theory to find the shortest path from a single starting node to all other nodes in a weighted grapph.

It is logic behind many moderns tecnologies, most notability Google Maps, where interactions are nodes and roads are edges with representing distance or travel time.

### How the algorithms works

Dijkstra's works on the principle of relaxation.It maintain a list of the "best-known distance" to every nodes. Initially, these are all set to infinity, except for source node, which is 0.

Step-by-Setp Logic:

1. Initialize:
  - Set the distance to the source node to 0.
  - Set the distance to all other nodes to `infinity`
  - Mark all nodes as unvisited.
  
2. Selection: Pick the unvisisted nodes with the smallest current distance (this is 'greedy' choice). Let's call this the "Current Nodes."
3. Relaxation: For the current Node, look at all its unvisited neighbors.
  - Calculate the tentative distance to each neighbor: `Distance to current node + Edge Weight to Neighbor`.
  - If this new distance is smaller that neighbor's previously recored distance, upgrade it.
4. Mark as Visited: Once all neighbor are checked, mark the current node as visited. A visited node is never checked again.
5. Repeat: Go back to Step until every node is visisted or the target is reached.
