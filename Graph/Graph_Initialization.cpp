#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V; // Number of vertices
    int E; // Number of edges
public:
    Graph(int V, int E){
        this->V = V;
        this->E = E;
    }; // Constructor
    unordered_map<int, vector<int>> adj; // Adjacency list representation of the graph
    void addEdge(int u, int v, bool directed = false) {
        if (directed) {
            adj[u].push_back(v);
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph
        }
    }
    void printGraph(){
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

};

int main() {
    int V = 5; // Number of vertices
    int E = 6; // Number of edges
    Graph g(V, E);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);

    g.printGraph();

    return 0;
}