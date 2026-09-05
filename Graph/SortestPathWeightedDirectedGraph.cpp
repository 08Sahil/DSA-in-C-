#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<list>
#include<limits>
using namespace std;
class Graph{
    private:
        int edge, vertex, weight;
    public:
        unordered_map<int, list<pair<int, int>>> Adj;
        void addEdge(int u, int v, int weight){
            pair<int, int>P = make_pair(v, weight);
            Adj[u].push_back(P);
        }

        void PrintAdj(){
            for(auto i : Adj){
                cout<<i.first <<" -> ";
                for(auto j : i.second){
                    cout<<"(" <<j.first <<" , "<<j.second<<") ";
                }
            }
        }
        void dfs(int nodes, unordered_map<int, bool> & visited, stack<int> &st){
            visited[nodes] = true;

            for(auto neighbour : Adj[nodes]){
                if(!visited[neighbour.first]){
                    dfs(neighbour.first, visited, st);
                }
            }
            st.push(nodes);
        }
        void getShortestPath(int nodes, stack<int> &st, vector<int> &Dist){
            Dist[nodes] = 0; 
            while(!st.empty()){
                int Top = st.top();
                st.pop();
                if(Dist[Top] != INT_MAX){
                    for(auto i: Adj[Top]){
                        if(Dist[Top] + i.second < Dist[i.first] ){
                            Dist[i.first] = Dist[Top] + i.second;
                        }
                    }
                }
            }
        }
    };

int main(){
        Graph g;
        g.addEdge(0,1,5);
        g.addEdge(0,2,3);
        g.addEdge(1,2,2);
        g.addEdge(1,3,6);
        g.addEdge(2,5,2);
        g.addEdge(2,4,4);
        g.addEdge(2,3,7);
        g.addEdge(3,4,-1);
        g.addEdge(4,5,-2);
        
        g.PrintAdj();

        //Topological Short 
        unordered_map<int, bool> visited;
        stack<int>st;
        int n = 6;// number of vertices
        for(int i = 0; i< n; i++){
            if(!visited[i]){
                g.dfs(i, visited, st);
            }
        }
        int Src = 1;
        vector<int> AnsShortestPath(n);
        for(int i = 0; i< n; i++){
            AnsShortestPath[i] = INT_MAX;
        }
        cout<<"Answer is "<<endl;
        g.getShortestPath(Src, st, AnsShortestPath);
        for(int i = 0; i< AnsShortestPath.size() ; i++){
            cout << AnsShortestPath[i] <<" ";
        }cout<<endl;
        return 0;
}