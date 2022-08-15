#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int sv, vector<vector<int>> &adjMatrix, vector<bool> &vis){
        vis[sv] = true;
        for(int i=0; i<adjMatrix[sv].size(); i++){
            if(adjMatrix[sv][i] == 1 && (!vis[sv])){
                dfs(i, adjMatrix, vis);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<bool> vis(grid.size(), false);
        dfs(0, grid, vis);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}