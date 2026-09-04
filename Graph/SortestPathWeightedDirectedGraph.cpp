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
        return 0;
}