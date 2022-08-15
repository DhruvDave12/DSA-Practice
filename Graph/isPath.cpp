#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, vector<int>> &adj;

    bool dfs(int sv, vector<bool> &vis){
        vis[sv] = true;

        for(auto it: adj[sv]){
            if(!vis[it]){
                dfs(it, vis);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int maxEle = INT_MIN;
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            maxEle = max(maxEle, max(edges[i][0], edges[i][1]));
        }    

        vector<bool> vis(maxEle, false);
        dfs(source, vis);

        if(vis[destination]) return true;

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}