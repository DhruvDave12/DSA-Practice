#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0) return;
        if(i >= n || j >= m) return;
        if(grid[i][j] != '1') return;
        if(vis[i][j]) return;

        vis[i][j] = true;

        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i, j-1);
        dfs(grid, vis, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>vis (grid.size(), vector<bool>(grid[0].size(), false));

        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    dfs(grid, vis, i, j);
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
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    Solution s;
    int ans = s.numIslands(grid);

    cout<<"ANS: "<<ans<<"\n";
     return 0;
}