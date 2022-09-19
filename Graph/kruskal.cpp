#include <bits/stdc++.h>
using namespace std;

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

class Node {
    public:
    int u;
    int v;
    int w;
};

struct CompareWeight {
    bool operator()(Node const &d1, Node const &d2){
        return d1.w > d2.w;
    }
};

class DSU {
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int N){
        for(int i=0; i<N; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(int u){
        if(u == parent[u]) return u;

        return parent[u] = findParent(parent[u]);
    }

    void doUnion(int u, int v){
        int x = findParent(u);
        int y = findParent(v);

        if(rank[x] > rank[y]){
            parent[y] = x;
        } else if(rank[y] > rank[x]){
            parent[x] = y;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
};



int kruskal(map<int,vector<pair<int,int>>> &graph, int N){
    priority_queue<Node, vector<Node>, CompareWeight> pq;
    for(auto it: graph){
        int u = it.first;
        for(auto itr: it.second){
            int v = itr.first;
            int w = itr.second;

            Node temp;
            temp.u = u;
            temp.v = v;
            temp.w = w;
            pq.push(temp);
        }
    }

    DSU ds(N);
    int ans = 0;
    while(!pq.empty()){
        Node temp = pq.top();
        pq.pop();
        int up = ds.findParent(temp.u);
        int vp = ds.findParent(temp.v);

        if(up != vp){
            ds.doUnion(temp.u, temp.v);
            ans += temp.w;
        }
    }

    return ans;
}

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

    
    int ans = kruskal(gh.adj, N);

    cout<<"ANS: "<<ans<<"\n";
    

    return 0;
}