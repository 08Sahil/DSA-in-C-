#include<vector>
#include<set>
#include<unordered_map>
#include<climits>
#include<list>
#include<iostream>

using namespace std;;

vector<int>ShortestPath(vector<vector<int>>&vec, int edge, int vertex, int source){
    //Adjaceny Matrix
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i< edge; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //Distance
    vector<int>dist(vertex);
    for(int i = 0; i< vertex; i++){
        dist[i]= INT_MAX;
    }

    //Set with Pair for (distance, nodes)
    set<pair<int, int>>st;
    dist[source] = 0;

    st.insert(make_pair(0,source));
    //run the loop while stack is not emplty

    while(!st.empty()){

        //fetch top record
        auto Top = *(st.begin());
        int topDistance = Top.first;
        int topNode = Top.second;

        st.erase(st.begin());
        //traverse neighbour
        for(auto neighbour : adj[topNode]){
            if(topDistance + neighbour.second <dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                //if record found
                if(record!= st.end()){
                    st.erase(record);
                }
                //update distance
                dist[neighbour.first] =topDistance + neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
       
    }
     return dist;
}

int main(){
vector<vector<int>>Graph;
Graph.push_back({0,1,5});
Graph.push_back({0,2,8});
Graph.push_back({1,0,5});
Graph.push_back({1,2,9});
Graph.push_back({1,3,2});
Graph.push_back({2,0,8});
Graph.push_back({2,1,9});
Graph.push_back({2,3,6});
Graph.push_back({3,1,2});
Graph.push_back({3,2,6});
vector<int>Path = ShortestPath(Graph, 10, 4, 0);
for(int i = 0; i<4; i++){
    cout<<Path[i]<<"-> ";
}
cout<<endl;
return 0;

}