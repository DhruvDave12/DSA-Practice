#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool isReachable(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }
    void solver(vector<vector<char>>& grid, int i, int j,vector<vector<bool>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        
        if(!isReachable(i,j,n,m)) return;
        if(vis[i][j]) return;
        vis[i][j] = true;
        if(grid[i][j] == '0') return;
        solver(grid,i+1,j,vis);
        solver(grid,i-1,j,vis);
        solver(grid,i,j+1,vis);
        solver(grid,i,j-1,vis);
        solver(grid,i-1,j-1,vis);
        solver(grid,i-1,j+1,vis);
        solver(grid,i+1,j-1,vis);
        solver(grid,i+1,j+1,vis);
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // we just have to find number of connected components in this question
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        int ans = 0;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    solver(grid,i,j,vis);
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}