#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int V;
    vector<list<pair<int, int>>> adj;

    Graph(int v) : V(v), adj(v)
    {
    }

    void addEdge(int v, int u, int weight = 1, bool directed = false)
    {
        adj[u].push_back({v, weight});
        if (!directed)
        {
            adj[v].push_back({u, weight});
        }
    }

    void printGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto const &edge : adj[i])
            {
                std::cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << "\n";
        }
    }
    // bfs
    void bfs(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS travelsal " << start << ": ";

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (auto const &edge : adj[u])
            {
                int v = edge.first;
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << "\n";
    }

    // dfs
    void dfs(int start)
    {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);

        cout << "DFS traversal " << start << ": ";

        while (!s.empty())
        {
            int u = s.top();
            s.pop();

            if (!visited[u])
            {
                visited[u] = true;
                cout << u << " ";

                for (auto const &edge : adj[u])
                {
                    int v = edge.first;
                    if (!visited[v])
                    {
                        s.push(v);
                    }
                }
            }
        }
        cout << "\n";
    }
};

int main()
{
    Graph gl(5);
    gl.addEdge(0, 1);
    gl.addEdge(0, 2);
    gl.addEdge(1, 3);
    gl.addEdge(2, 4);
    gl.printGraph();
    gl.bfs(0);
    gl.dfs(0);

    return 0;
}