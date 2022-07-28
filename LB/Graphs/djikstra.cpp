#include <bits/stdc++.h>
using namespace std;

// We are given an undirected graph and we have to find the min dist to reach any node
// we can use priority queue to get always the minimum dist and then query it in the adj list and then we are done

class Graph {
    public:
    map<int,vector<pair<int,int>>> adj;
    
    Graph(){
        adj.clear();
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
};

vector<int> djikstraEffMethod(map<int,vector<pair<int,int>>>&adj, int sv, int N){
    // node struct -> (dist,nodeVal)
    // used min priority queue to get the minimum distance nodes always first and we get the absolute minimum distance possible
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minQueue;
    minQueue.push({0,sv});
    vector<int> dist(N, INT_MAX);
    dist[sv] = 0;
    while(!minQueue.empty()){
        pair<int,int> p = minQueue.top();
        minQueue.pop();

        for(auto i: adj[p.second]){
            if(dist[i.first] > dist[p.second]+i.second){
                dist[i.first] = dist[p.second]+i.second;
                minQueue.push({dist[i.first], i.first});
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
    gh.addEdge(1,2,2);
    gh.addEdge(1,4,1);
    gh.addEdge(4,3,3);
    gh.addEdge(2,3,4);
    gh.addEdge(2,5,5);
    gh.addEdge(3,5,1);

    vector<int> ans = djikstraEffMethod(gh.adj, 1, 6);

    for(int i=0; i<ans.size(); i++){
        cout<<i<<" "<<ans[i]<<"\n";
    }
    return 0;
}