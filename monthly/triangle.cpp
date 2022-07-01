#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle, vector<vector<int>> dp = vector<vector<int>>(200, (vector<int>(200,1e6))), int N=0, int M=0) {
        // recursiely travel to all the positions in a triangle
        if(N > triangle.size()){
            return 0;
        }
        // if(dp[N][M] < 1e6){
        //     return 
        // }
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}