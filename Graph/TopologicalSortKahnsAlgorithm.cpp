#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

vector<int> TopologicalSort(vector<vector<int>>&edges, int V, int E){
    //Create ADjacency Matrix
    unordered_map<int, list<int>>Adj;
    for(int i = 0; i< E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        Adj[u].push_back(v);
    }
    //Find all indegree 
    vector<int>Indegree(V);
    for(auto i:Adj){
        // cout << "The Adj Value for incresing the indegree "<< i.first<<endl;
        for(auto j : i.second){
            Indegree[j]++;
            // cout<<"Printing the value of J "<<j <<" ";
        }
    }
    //Push all the zero Indegree
    queue<int>q;
    for(int i = 0; i<V; i++){
        if(Indegree[i] == 0){
            q.push(i);
        }
    }
    //Do BFS
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
         
        //neighbour indegree update
        for(auto neighbour : Adj[front]){
            Indegree[neighbour]--;
            if(Indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
        


    }
    return ans;
    
}

int main(){
vector<vector<int>> edges{
    {0,1},
    {0,2},
    {1,4},
    {2,4},
    {4,3}
};    vector<int > TopologicalAnswer = TopologicalSort(edges, 5, 5);
    for(int i = 0; i<5; i++){
    cout << TopologicalAnswer[i] << " ";
}
}