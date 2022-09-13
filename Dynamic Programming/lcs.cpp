#include <bits/stdc++.h>
using namespace std;

int lcsLen(string x, string y, int n1, int n2){
    if(n1 <= 0 || n2 <= 0) return 0;
    if(x[n1-1] == y[n2-1]) return 1 + lcsLen(x, y, n1-1, n2-1);

    int moveX = lcsLen(x,y,n1-1,n2);
    int moveY = lcsLen(x,y,n1,n2-1);

    return max(moveX, moveY);
}

// bottom up (memoization)
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solverDP(int n1, int n2, string x, string y, vector<vector<int>> &dp){
        if(n1 == 0 || n2 == 0) return 0;
        
        if(dp[n1][n2] != -1) return dp[n1][n2];
        
        if(x[n1-1] == y[n2-1]) return dp[n1][n2] = 1 + solverDP(n1-1, n2-1, x, y,dp);

        int moveX = solverDP(n1-1,n2,x,y,dp);
        int moveY = solverDP(n1,n2-1,x,y,dp);

        return dp[n1][n2] = max(moveX, moveY);
    }

    int lcs(int n1, int n2, string x, string y)
    {
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

        return solverDP(n1,n2,x,y,dp);
    }
};

int lcsTopDown(int n1, int n2, string x, string y){
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
    for(int i=0; i<n1+1; i++){
        for(int j=0; j<n2+1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<n1+1; i++){
        for(int j=1; j<n2+1; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n1][n2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string x = "abcdgh";
    string y = "abcdxh";

    // int ans = lcsLen(x,y,x.length(), y.length());
    int ans = Solution().lcs(x.size(), y.size(),x, y);
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}