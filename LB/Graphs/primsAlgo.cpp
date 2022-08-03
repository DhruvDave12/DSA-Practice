#include <bits/stdc++.h>
using namespace std;

// Prims algo is used to find the Minimum Spanning Tree -> (Edges = Vertices - 1) and (Minimum weight)
// No cycle in MST (Minimum Spanning Tree)
// In prims algo we just have to choose the minimum weight from all available edges.

class Graph {
    public:
    map<int, vector<pair<int,int>>> adj;

    void addEdgeUndirected(int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
};

class Prims {
    public:

    bool checkVisited(vector<bool> vis){
        for(int i=0; i<vis.size(); i++){
            if(vis[i] == false) return false;
        }
        return true;
    }

    pair<int, map<int, vector<pair<int,int>>>> primsAlgoEff(map<int,vector<pair<int,int>>> &adj, int sv, int N){
        vector<bool> vis(N, false);
        vector<int> key(N, INT_MAX);
        vector<int> parent(N, INT_MAX);

        key[sv] = 0;
        parent[sv] = -1;

        for(int c = 0; c < N-1; c++){
            // find the minimum in they key vector

            int mini = INT_MAX, u;
            for(int i=0; i<key.size(); i++){
                if(!vis[i] && key[i] < mini){
                    mini = key[i];
                    u = i;
                }
            }

            vis[u] = true;
            // now i got the minimum node in u and also the minimal weight
            for(auto it: adj[u]){
                int toVisit = it.first;
                int weight = it.second;

                if(!vis[toVisit] && weight < key[toVisit]){
                    parent[toVisit] = u, key[toVisit] = weight;
                }
            }
        }
        map<int,vector<pair<int,int>>> mp;
        int ans = 0;
        for(int i=1; i<parent.size(); i++){
            ans += key[i];
            mp[parent[i]].push_back({i, key[i]});
        }

        pair<int,map<int,vector<pair<int,int>>>> res = make_pair(ans, mp);

        return res;
    }  


    pair<int, map<int, vector<pair<int,int>>>> primsAlgoHeap(map<int,vector<pair<int,int>>> &adj, int sv, int N){
        vector<bool> vis(N, false);
        vector<int> key(N, INT_MAX);
        vector<int> parent(N, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minPQ;

        key[sv] = 0;
        parent[sv] = -1;
        minPQ.push({sv,0});

        for(int c=0; c<N-1; c++){
            int u = minPQ.top().second;
            minPQ.pop();

            vis[u] = true;
            for(auto itr : adj[u]){
                int v = itr.first;
                int weight = itr.second;

                if(!vis[v] && weight < key[v]){
                    parent[v] = u;
                    key[v] = weight;
                    minPQ.push({key[v], v});
                }
            }
        }

        map<int, vector<pair<int,int>>> mp;
        int ans = 0;
        for(int i=1; i<parent.size(); i++){
            ans += key[i];
            mp[parent[i]].push_back({i, key[i]}); 
        }

        pair<int,map<int,vector<pair<int,int>>>> res = make_pair(ans, mp);

        return res;
    }  
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;

    gh.addEdgeUndirected(0,1,2);
    gh.addEdgeUndirected(0,3,6);
    gh.addEdgeUndirected(1,3,8);
    gh.addEdgeUndirected(1,4,5);
    gh.addEdgeUndirected(1,2,3);
    gh.addEdgeUndirected(2,4,7);
    
    int sv = 0;
    int N = 5;

    Prims pr;

    // pair<int, map<int,vector<pair<int,int>>>> ans = pr.primsAlgoEff(gh.adj,sv,N);
    pair<int, map<int,vector<pair<int,int>>>> ans = pr.primsAlgoHeap(gh.adj,sv,N);

    cout<<"MIN WEIGHT: "<<ans.first<<"\n";

    cout<<"EDGES ARE: "<<"\n";
    map<int,vector<pair<int,int>>> :: iterator itr;
    for(itr = ans.second.begin(); itr != ans.second.end(); itr++){
        cout<<itr->first<<" : \n";
        for(int i=0; i<itr->second.size(); i++){
            cout<<itr->second[i].first<<" weighs "<<itr->second[i].second<<"\n";
        }
        cout<<"\n";
    } 

    return 0;
}