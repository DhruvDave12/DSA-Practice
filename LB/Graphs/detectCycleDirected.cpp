#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(vector<int> adj[], vector<bool> &vis, int v, vector<bool> & recVis){
        vis[v] = true;
        recVis[v] = true;
        for(auto i: adj[v]){
            if(!vis[i]){
                if(helper(adj, vis, i, recVis)){
                    return true;
                }
            }
            if(recVis[i]) return true;
        }
        recVis[v] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> recVis(V, false);
        bool ans = helper(adj, vis, 0, recVis);
        return ans;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}