#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, vector<pair<int, int>>> adj;

    void addEdgeDirected(int u, int v, int wt)
    {
        adj[u].push_back({v, wt});
    }
};

class Bellman {
    public:
    vector<int> bellManImplementation(map<int,vector<pair<int,int>>> &adj, int N){
        int maxx = 1000000;
        vector<int> dist(N, maxx);
        dist[0] = 0;

        // N-1 times relaxations
        for(int i=1; i<= N-1; i++){
            for(auto it: adj){
                for(auto itr: adj[it.first]){
                    if(dist[itr.first] > dist[it.first] + itr.second){
                        dist[itr.first] = dist[it.first] + itr.second;
                    }
                }
            }
        }      


        // now we will check if any negative edge cycle is there or not
        // if it again changes then we print that
        bool flag = false;

        for(auto it: adj){
            for(auto itr: adj[it.first]){
                if(dist[itr.first] > dist[it.first] + itr.second){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        if(flag) cout<<"Negative Cycle Exists";

        return dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph gh;
    gh.addEdgeDirected(0, 1, 5);
    gh.addEdgeDirected(1, 5, -3);
    gh.addEdgeDirected(1, 2, -2);
    gh.addEdgeDirected(5, 3, 1);
    gh.addEdgeDirected(3, 2, 6);
    gh.addEdgeDirected(3, 4, -2);
    gh.addEdgeDirected(2, 4, 3);

    Bellman bl;

    vector<int> res = bl.bellManImplementation(gh.adj,6);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    
    return 0;
}