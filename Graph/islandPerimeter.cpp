#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // move to only ones  
    void dfs(vector<vector<int>> &adj, int &res, int i, int j, vector<vector<bool>> &vis){
        if(i < 0 || i >= adj.size()) return;
        if(j < 0 || j >= adj[0].size()) return;

        vis[i][j] = true;

        if(adj[i][j] == 1) {
            if(i+1 == adj.size()) res++;
            if(i-1 == -1) res++;
            if(j-1 == -1) res++;
            if(j+1 == adj[0].size()) res++; 
            if(i+1 < adj.size() && adj[i+1][j] == 0) res++;
            if(i-1 >= 0 && adj[i-1][j] == 0) res++;
            if(j+1 < adj[0].size() && adj[i][j+1] == 0) res++;
            if(j-1 >= 0 && adj[i][j-1] == 0) res++;
        }
        
        if(((i-1) >= 0) && !vis[i-1][j]){
            dfs(adj, res, i-1, j, vis);
        }
        if(((i+1) < adj.size()) && !vis[i+1][j]){
            dfs(adj, res, i+1, j, vis);
        }
        if(((j-1) >= 0) && !vis[i][j-1]){
            dfs(adj, res, i, j-1, vis);
        }
        if(((j+1) < adj[0].size()) && !vis[i][j+1]){
            dfs(adj, res, i, j+1, vis);   
        }


        // for(int k=j+1; k<adj[0].size(); k++){
        //     if(adj[i][k] == 1 && !vis[i][k]) {
        //         dfs(adj, res, i, k, vis);
        //     }
        // }
        // for(int k=i+1; k<adj.size(); k++){
        //     if(adj[k][j] == 1 && !vis[k][j]){
        //         dfs(adj, res, k, j, vis);
        //     }
        // }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int i = 0;
        int j = 0;
        int N = grid.size();
        int M = grid[0].size();
    
        vector<vector<bool>> vis(N, vector<bool>(M, false));
        dfs(grid, res, i, j, vis);
        return res;
    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    vector<vector<int>> vec = {
        {0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}
    };

    Solution s;
    int ans = s.islandPerimeter(vec);
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}