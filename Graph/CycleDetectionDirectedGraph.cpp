#include <unordered_map>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

class Graph {
    int V;
    int E;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    unordered_map<int, vector<int>> adj;

    void addEdge(int u, int v, bool directed = false) {
        if (directed) {
            adj[u].push_back(v);
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";

            for (int j : adj[i]) {
                cout << j << " ";
            }

            cout << endl;
        }
    }
};


bool IsDFSCyclic(
    int node,
    unordered_map<int, bool>& visited,
    unordered_map<int, bool>& DFSVisited,
    unordered_map<int, list<int>>& Adj
) {
    // Mark current node as visited
    visited[node] = true;

    // Mark current node as part of current DFS path
    DFSVisited[node] = true;

    for (auto neighbour : Adj[node]) {

        // If neighbour has not been visited
        if (!visited[neighbour]) {

            bool cycleDetected =
                IsDFSCyclic(neighbour, visited, DFSVisited, Adj);

            if (cycleDetected) {
                return true;
            }
        }

        // Neighbour is already visited
        else {
            // If neighbour is still in current DFS path,
            // then we have a cycle
            if (DFSVisited[neighbour]) {
                return true;
            }
        }
    }

    // Remove node from current DFS path
    DFSVisited[node] = false;

    return false;
}


bool IsCycleDirectedGraph(
    int n,
    vector<pair<int, int>>& edges
) {
    unordered_map<int, list<int>> Adj;

    // Build directed adjacency list
    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i].first;
        int v = edges[i].second;

        Adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSVisited;

    // Check every connected component
    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            bool FoundCycle =
                IsDFSCyclic(i, visited, DFSVisited, Adj);

            if (FoundCycle) {
                return true;
            }
        }
    }

    return false;
}


int main() {

    int V = 5;
    int E = 6;

    Graph g(V, E);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);

    g.printGraph();


    // For directed graph cycle detection,
    // use vector<pair<int, int>>
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3}
    };


    // Correct function call:
    bool hasCycle = IsCycleDirectedGraph(V, edges);

    cout << "Cyclic graph is detected or not: "
         << (hasCycle ? "Yes" : "No")
         << endl;

    return 0;
}