#include <bits/stdc++.h>
using namespace std;

class Graph {

    public:
    map<int,vector<int>> adj;    
    Graph(){
        adj.clear();
    }

    void addEdgeUndirected(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

void getShortestDistance(map<int,vector<int>>&adj, int src, vector<int>&dist){
    dist[src] = 0;

    queue<int> q;
    q.push(src);
    vector<bool> vis(dist.size(), false);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        vis[temp] = true;
        for(auto i: adj[temp]){
            dist[i] = min(dist[i], (1+dist[temp]));
            if(!vis[i]){
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;
    gh.addEdgeUndirected(0,1);
    gh.addEdgeUndirected(0,3);
    gh.addEdgeUndirected(1,3);
    gh.addEdgeUndirected(1,2);
    gh.addEdgeUndirected(3,4);
    gh.addEdgeUndirected(4,5);
    gh.addEdgeUndirected(5,6);
    gh.addEdgeUndirected(2,6);
    gh.addEdgeUndirected(6,7);
    gh.addEdgeUndirected(7,8);


    vector<int> dist(9, INT_MAX);
    getShortestDistance(gh.adj, 0, dist);

    for(int i=0; i<dist.size(); i++){
        cout<<i<<" : "<<dist[i]<<"\n";
    }

    return 0;
}