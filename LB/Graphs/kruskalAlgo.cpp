#include <bits/stdc++.h>
using namespace std;

// Kruskal algorithm is used to find the minimum spanning tree
// We wont use a graph ds in fact we will use disjoint set data structure.

// We sort the nodes according to their weight in ascending order always pick up the edge and it if it belongs to same component then remove else attach it.

class Graph {
    public:
    map<int,vector<pair<int,int>>> adj;
    
    void addEdgeUndirected(int u, int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void addEdgeDirected(int u, int v, int w){
        adj[u].push_back({v,w});
    }
};

class myDS {
    public:
    int w;
    int u;
    int v;
};

struct CompareWeight {
    bool operator()(myDS const& d1, myDS const& d2)
    {
        return d1.w > d2.w;
    }
};

class DisjointSet {
    public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int N){
        for(int i=0; i<N; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findParent(int u){
        if(u == parent[u]) return u;

        return parent[u] = findParent(parent[u]);
    }

    void doUnion(int u, int v){
         u = findParent(u);
         v = findParent(v);

        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
};

class Kruskal {
    public:

    map<int, vector<pair<int,int>>> getMSTKruskal(priority_queue<myDS, vector<myDS>, CompareWeight> &pq, int N){
        DisjointSet ds(N);
        map<int,vector<pair<int,int>>> mp;

        while(!pq.empty()){
            myDS temp = pq.top();
            if(ds.findParent(temp.u) != ds.findParent(temp.v)){
                ds.doUnion(temp.u, temp.v);
                mp[temp.u].push_back({temp.v, temp.w});
            }
            pq.pop();
        }

        return mp;
    }  
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;

    Graph gh;
    
    gh.addEdgeUndirected(5, 1, 4);
    gh.addEdgeUndirected(5, 4, 9);
    gh.addEdgeUndirected(4, 1, 1);
    gh.addEdgeUndirected(4, 3, 5);
    gh.addEdgeUndirected(4, 2, 3);
    gh.addEdgeUndirected(1, 2, 2);
    gh.addEdgeUndirected(3, 2, 3);
    gh.addEdgeUndirected(3, 6, 8);
    gh.addEdgeUndirected(2, 6, 7);


    priority_queue<myDS, vector<myDS>, CompareWeight> pq;

    map<int, vector<pair<int,int>>> :: iterator it;
    for(it=gh.adj.begin(); it != gh.adj.end(); it++){
        int u = it->first;
        for(int i=0; i<it->second.size(); i++){
            myDS temp;
            temp.u = u;
            temp.v = it->second[i].first;
            temp.w = it->second[i].second;
            pq.push(temp);
        }
    }

    Kruskal ks;
    map<int,vector<pair<int,int>>> ans = ks.getMSTKruskal(pq, N);

    int weight = 0;
    for(it = ans.begin(); it != ans.end(); it++){
        for(int i=0; i<it->second.size(); i++){
            weight += it->second[i].second;
            cout<<it->first<<" is attached to "<<it->second[i].first<<" which weighs "<<it->second[i].second<<"\n";
        }
        cout<<"\n";
    }

    cout<<"Weight of minimum spanning tree is: "<<weight<<"\n";

    return 0;
}