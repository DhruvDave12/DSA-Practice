#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int,vector<int>> adj;
    
    void addEdgeUndirected(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void addEdgeDirected(int u, int v){
        adj[u].push_back(v);
    }
};

// Disjoint set is a data structure which is used to do these two tasks in a heirarchial data structure very easily
// 1. Find parent of any connected component 
// 2. Join two sets (trees)

// We implement it using Union by rank and Path Compression technique.
// 1. Union by rank means we have to keep the time complexity as low as possible so we try to make the depth of tree as low as possible.
// 2. Path compression means if we want to access the parent of any node which is very deep in tree we wont have to traverse instead make an N-Ary Tree to directly get the parent

// Time Complexity -> O(4) = O(1) = Constant Time
// Space Complexity -> O(N) = (Two arrays are being used)

// Now we will implement it.
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
        // if it is its own parent in the initial stages then we can use this
        if(u == parent[u]) return u;

        // else we recursively go to the parents and do path compression by storing the final parent in that array

        return parent[u] = findParent(parent[u]);
    }

    void doUnion(int u, int v){
        u = findParent(u);
        v = findParent(v);

        // always attack the smaller trees
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else {
            // attack to anyone and increase the rank of the parent
            parent[v] = u;
            rank[u]++;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;

    DisjointSet ds(N);

    while(N--){
        int u, v;
        cin>>u>>v;
        ds.doUnion(u,v);
    }

    int par1 = ds.findParent(4);
    int par2 = ds.findParent(7);

    cout<<"Parent of 4 is: "<<par1<<"\n";
    cout<<"Parent of 7 is: "<<par2<<"\n";

    return 0;
}