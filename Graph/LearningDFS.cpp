#include<unordered_map>
#include<vector>
#include"Graph_initialization.cpp"
using namespace std;

class Graph{
    private:
    int edge, vertax;
    Graph(int edge, int vertax){
        this->edge = edge;
        this-> vertax = vertax;
    }
    public:
    void dfs(int node, unordered_map<int, bool > &visited, 
            unordered_map<int, list<int>> &adj, vector<int> & component){
                component.push_back(node);
                visited[node] = true;

                for(auto i: adj[node]){
                    if(!visited[i]){
                        dfs(i, visited, adj, component);
                    }
                }
            }

};