#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

bool CycleDetectionBFSTopologicalSort(vector<vector<int>>&edges, int V, int E){
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
        // cout << "The Adj Value for incresing the indegree "<< i.first;
        for(auto j : i.second){
            Indegree[j]++;
            // cout<<" >> "<<j;
        }
        // cout<<endl;
    }
    //Push all the zero Indegree
    queue<int>q;
    for(int i = 0; i<V; i++){
        if(Indegree[i] == 0){
            q.push(i);
        }
    }
    //Do BFS
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout<< "The front value is " <<front <<endl;
        cnt++;
        cout<<"The counter value is "<< cnt <<endl;
         
        //neighbour indegree update
        for(auto neighbour : Adj[front]){
            // cout<<neighbour <<" ";
            Indegree[neighbour]--;
            if(Indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    if(cnt == V){
        return false;
    }
    else{
        return true;
    }
    
}

int main(){
vector<vector<int>> edges{
    {0,1},
    {0,2},
    {1,4},
    {2,4},
    {4,3}
};    
bool Answer = CycleDetectionBFSTopologicalSort(edges, 5, 5);
cout <<"Is it the cycle or not "<< Answer<<endl; 
}