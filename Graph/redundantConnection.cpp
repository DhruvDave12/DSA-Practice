#include <bits/stdc++.h>
using namespace std;

// Basic DSU Implementation
class DSU {
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int N){
        for(int i=0; i<N+1; i++){
            parent.push_back(i);
            rank.push_back(0);
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

class Solution {
public:
    // we can use the Disjoint Set Union implementation
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        stack<vector<int>> st;
        int N = edges.size();
        DSU ds(N);
        for(auto it: edges){
            // cout<<it[0]<<" "<<it[1]<<"\n";
            int p1 = ds.findParent(it[0]);
            int p2 = ds.findParent(it[1]);
            
            // cout<<p1<<" "<<p2<<"\n";
            if(p1 == p2){
                st.push(it);
            }
            
            ds.doUnion(it[0], it[1]);
            
        }
        
        return st.top();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution s;
    vector<int> vec;
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};

    vec = s.findRedundantConnection(edges);

    for(auto it: vec) cout<<it<< " ";
    return 0;
}