#include<unordered_map>
#include<list>
#include<vector>
#include<iostream>

using namespace std;

// Forward declaration
bool isCyclicDFS(int nodes, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>>& Adj);

class Graph {
    int V;
    int E;
public:
    Graph(int V, int E){
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

bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>>& Adj) {
    visited[node] = true;
    
    for(auto neighbour : Adj[node]){
        if(!visited[neighbour]){
            if(isCyclicDFS(neighbour, node, visited, Adj))
                return true;
        }
        else if(neighbour != parent) {
            return true;
        }
    }
    return false;
}

bool CycleDetectionDFS(vector<vector<int>>& edges, int m, int n) {
    unordered_map<int, list<int>> Adj;
    
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    
    unordered_map<int, bool> visited;
    
    // Check all nodes (for disconnected graph)
    for(int i = 0; i < n; i++){
        if(!visited[i]) {
            if(isCyclicDFS(i, -1, visited, Adj))
                return true;
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
    
    // Create edges vector for CycleDetectionDFS
    vector<vector<int>> edges = {{0,1}, {0,4}, {1,2}, {1,3}, {1,4}, {2,3}};
    bool hasCycle = CycleDetectionDFS(edges, 6, 5);
    cout << "Cyclic graph is detected or not: " << (hasCycle ? "Yes" : "No") << endl;
    
    return 0;
}