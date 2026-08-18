#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;
void TopologicalSort(int node, unordered_map<int, list<int>>&Adj, unordered_map<int, bool> &Visited, stack<int> &st){
    Visited[node] = true;

    for(auto neighbour : Adj[node]){
        if(!Visited[node]){
            TopologicalSort(neighbour, Adj, Visited, st);
        }
    }
    st.push(node);
}
vector<int> TopologicalSort(int m, int n, vector<vector<int>>&edges ){
    unordered_map<int, list<int>>adj;
    
    for(int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    stack<int>st;
    unordered_map<int, bool>Visited;
    for(int i = 0; i<n; i++){
        if(!Visited[i]){
            TopologicalSort(i, adj, Visited, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    // Create edges vector for topology sort
    vector<vector<int>> edges = {{0,1}, {0,4}, {1,2}, {1,3}, {1,4}, {2,3}};
    vector<int> HasTopologySort = TopologicalSort( 6, 5, edges);
    for(int i = 0; i<HasTopologySort.size(); i++){
        cout<< HasTopologySort[i]<<" ";
    }    
}