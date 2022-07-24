#include <bits/stdc++.h>
using namespace std;

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

void getTopo(map<int,vector<pair<int,int>>>&adj, int sv, int N){
    stack<int> st;
    vector<bool> vis(N, false);

    getTopoUtil(adj,st,vis,0);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
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

    getTopo(gh.adj, 0, 6);
    return 0;
}