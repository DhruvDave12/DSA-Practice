#include <bits/stdc++.h>
using namespace std;

// We need number of disconnected components 
// We need number of edges
// if edges > number of diconnected components we can return the ans as number of disconnected components
// else return -1

class Solution {
public: 

    void dfs(vector<vector<int>> &connections, int sv, vector<bool> &vis){
        vis[sv] = true;
        for(auto it: connections[sv]){
            if(!vis[it]) {
                dfs(connections, it, vis);
            }
        }
    }

    int getConnectedComponents(vector<vector<int>> &connections, int n) {
        vector<bool> vis(n, false);
        int res = 0;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                res++;
                dfs(connections, i, vis);
            }
        }

        return res;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        int connectedComps = getConnectedComponents(connections, n) - 1;

        if(edges > connectedComps) return connectedComps;
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}