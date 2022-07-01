#include <bits/stdc++.h>
using namespace std;

int lcs( string X, string Y, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return dp[m][n] =  1 + lcs(X, Y, m-1, n-1, dp);
    
    if(dp[m][n] != -1){
        // if already calculated then return that value
        return dp[m][n];
    }
    else
    // else we store it inside the dp table and then go to next iteration
        return dp[m][n] = max(lcs(X, Y, m, n-1, dp), lcs(X, Y, m-1, n, dp));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string A = "altruism";
    string B = "plasma";
    vector<vector<int>> dp(A.length()+1, vector<int>(B.length() + 1, -1));

    cout<<lcs(A, B, A.length(), B.length(), dp);
    

    return 0;
}