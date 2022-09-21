#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9+10
#define N 510

class Graph {
    public:
    map<int,vector<pair<int,int>>> adj;

    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
    }
};

vector<vector<int>> floydWarshall(int V, map<int,vector<pair<int,int>>> &adj){
    vector<vector<int>> dist(V+1, vector<int>(V+1, MAX));

    for(int i=0; i<dist.size(); i++){
        for(int j=0; j<dist[i].size(); j++){
            if(i==j) dist[i][j] = 0;
        }
    }

    for(auto itr: adj){
        for(auto it: itr.second){
            dist[itr.first][it.first] = it.second;
        }
    }

    // floyd warshal
    for(int k=1; k<=V; k++){
        for(int i=0; i<=V; i++){
            for(int j=0; j<=V; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;

    gh.addEdge(1,2,1);
    gh.addEdge(1,3,5);
    gh.addEdge(2,3,2);
    gh.addEdge(3,5,2);
    gh.addEdge(2,5,1);
    gh.addEdge(2,4,2);
    gh.addEdge(4,5,3);
    gh.addEdge(4,6,1);
    gh.addEdge(5,6,2);
    
    vector<vector<int>> res = floydWarshall(6,gh.adj);

    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            if(res[i][j] == MAX) cout<<"I"<<" ";
            else cout<<res[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}