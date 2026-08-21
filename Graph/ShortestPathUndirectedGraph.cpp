// #include<vector>
// #include<unordered_map>
// #include<list>
// #include<iostream>
// #include<queue>
// using namespace std;

// vector<int> ShortestPath(vector<vector<int>>&edges, int m, int n, int FirstNd, int SecNd){
// //Creating Adjacency List

// unordered_map<int, list<int>> Adj;
// for(int i = 0; i < m; i++){
//     int u = edges[i][0];
//     int v = edges[i][1];

//     Adj[u].push_back(v);
//     Adj[v].push_back(u);
// }
// //Visited 
// unordered_map<int, bool>Visited;
// //Parents Tracking
// unordered_map<int , int> Parents;

// //BFS Queues
// queue<int>q;
// //for disconnect graph

// q.push(FirstNd);
// Visited[FirstNd] = true;

// Parents[FirstNd] = -1;

// while(!q.empty()){
//     int front = q.front();
//     q.pop();
//     for(auto neighbour : Adj[front]){

//         if(!Visited[neighbour]){
//             Visited[neighbour] = true;
//             Parents[neighbour] = front;
//             q.push(neighbour);
//         }
        
//     }    
// }

//     vector<int>ans;
//     for(int i = 0; i< n; i++){
//         bool AnsPath = false;
//         if(Parents[i] == FirstNd || AnsPath){
//             ans.push_back(i);
//             AnsPath = true;
//         }
//         if(Parents[i] = SecNd){
//             AnsPath = false;
//         }
//     }
//     return ans;

// }

// int main(){
// vector<vector<int>> edges{
//     {1,2},
//     {1,3},
//     {1,4},
//     {2,3},
//     {3,8},
//     {4,6}, 
//     {5,8},{6,7}, {7,8}
// };    vector<int > Path = ShortestPath(edges, 9, 8, 1, 8);
//     for(int i = 0; i<5; i++){
//     cout << Path[i] << " ";
// }
// }

#include <vector>
#include <unordered_map>
#include <list>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> ShortestPath(vector<vector<int>>& edges, int m, int n,
                         int FirstNd, int SecNd)
{
    // Creating Adjacency List
    unordered_map<int, list<int>> Adj;

    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    // Visited
    unordered_map<int, bool> Visited;

    // Parents Tracking
    unordered_map<int, int> Parents;

    // BFS Queue
    queue<int> q;

    q.push(FirstNd);
    Visited[FirstNd] = true;
    Parents[FirstNd] = -1;

    // BFS
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour : Adj[front])
        {
            if(!Visited[neighbour])
            {
                Visited[neighbour] = true;
                Parents[neighbour] = front;

                q.push(neighbour);
            }
        }
    }

    // If destination was not reached
    if(!Visited[SecNd])
    {
        return {};
    }

    // Reconstruct path
    vector<int> ans;

    int current = SecNd;

    while(current != -1)
    {
        ans.push_back(current);
        current = Parents[current];
    }

    // Reverse path
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<vector<int>> edges
    {
        {1,2},
        {1,3},
        {1,4},
        {2,3},
        {3,8},
        {4,6},
        {5,8},
        {6,7},
        {7,8}
    };

    vector<int> Path = ShortestPath(edges, 9, 8, 1, 8);

    for(int node : Path)
    {
        cout << node << " ";
    }

    return 0;
}