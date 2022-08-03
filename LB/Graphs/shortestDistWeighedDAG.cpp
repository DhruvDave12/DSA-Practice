#include <bits/stdc++.h>
using namespace std;

// In directed graphs the shortest distance in the graph will come from topological way
// get topological order and then traverse with the logic.
class Graph {
    public:
    map<int, vector<pair<int,int>>> adj;

    void addEdgeDirected(int u, int v, int w){
        adj[u].push_back({v,w});
    }
};

void getTopoUtil(map<int,vector<pair<int,int>>>&adj, stack<int>&st, vector<bool>&vis, int sv){
    vis[sv] = true;
    for(auto it: adj[sv]){
        if(!vis[it.first]){
            getTopoUtil(adj, st, vis, it.first);
        }
    }
    st.push(sv);
}

stack<int> getTopo(map<int,vector<pair<int,int>>>&adj, int sv, int N){
    stack<int> st;
    vector<bool> vis(N, false);

    getTopoUtil(adj,st,vis,0);

    return st;
}

void getShortestDistDAG(map<int,vector<pair<int,int>>>&adj, int sv, vector<int>&dist, int N){
    stack<int> topo = getTopo(adj, sv, N);
    // assuming that top element is the source

    dist[topo.top()] = 0;
    while(!topo.empty()){
        int node = topo.top();
        for(auto it: adj[node]){
            if(dist[node]+it.second < dist[it.first]){
                dist[it.first] = dist[node]+it.second;
            }
        }
        topo.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;
    gh.addEdgeDirected(0,1,2);
    gh.addEdgeDirected(0,4,1);
    gh.addEdgeDirected(1,2,3);
    gh.addEdgeDirected(4,2,2);
    gh.addEdgeDirected(4,5,4);
    gh.addEdgeDirected(2,3,6);
    gh.addEdgeDirected(5,3,1);

    vector<int> dist(6, INT_MAX);
    getShortestDistDAG(gh.adj, 0, dist, 6);

    for(int i=0; i<dist.size(); i++){
        cout<<i<<" : "<<dist[i]<<"\n";
    }

    return 0;
}