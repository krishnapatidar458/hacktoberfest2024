#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<int> topologicalSort() {
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int u = 0; u < V; ++u) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            for (int v : adj[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (topoOrder.size() != V) {
            cout << "The graph contains a cycle!" << endl;
            return vector<int>();
        }

        return topoOrder;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    vector<int> topoOrder = graph.topologicalSort();
    if (!topoOrder.empty()) {
        for (int u : topoOrder) {
            cout << u << " ";
        }
        cout << endl;
    }

    return 0;
}
