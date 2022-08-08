#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:

    map<int, vector<int>> adj;
    void addEdgeInUndirected(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

class Bridges {
    public:

    void dfs(map<int,vector<int>>&adj, int node, int parent, int &timer, vector<bool> &vis, vector<int> &low, vector<int> &tin){
        vis[node] = true;
        tin[node] = low[node] = timer++;

        for(auto it: adj[node]){
            if(it == parent){
                // if visited and it parent so continue
                continue;
            }
            if(!vis[it]){
                dfs(adj, it, node, timer, vis, low, tin);
                // now when we are returning we will check the low and tin
                low[node] = min(low[node], low[it]);
                
                if(low[it] > tin[node]){
                    // means we are at a different component
                    cout<<it<<" - "<<node<<"\n";
                }
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

    void printBridges(map<int, vector<int>> &adj, int N){
        vector<bool> vis(N, false);
        vector<int> tin(N, -1);
        vector<int> low(N, -1);
        int timer = 0;

        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfs(adj, i, -1, timer, vis, low, tin);
            }
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;
    gh.addEdgeInUndirected(1,2);
    gh.addEdgeInUndirected(1,4);
    gh.addEdgeInUndirected(2,3);
    gh.addEdgeInUndirected(3,4);
    gh.addEdgeInUndirected(4,5);
    gh.addEdgeInUndirected(5,6);
    gh.addEdgeInUndirected(6,7);
    gh.addEdgeInUndirected(6,9);
    gh.addEdgeInUndirected(7,8);
    gh.addEdgeInUndirected(8,10);
    gh.addEdgeInUndirected(10, 11);
    gh.addEdgeInUndirected(10,12);
    gh.addEdgeInUndirected(11, 12);

    int N = 12;
    Bridges bdg;

    bdg.printBridges(gh.adj, N);

    return 0;
}