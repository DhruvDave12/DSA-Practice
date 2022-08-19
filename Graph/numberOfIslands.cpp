#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // it is same like number of connected components in a grid
    int numIslands(vector<vector<char>> &grid)
    {  
        
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