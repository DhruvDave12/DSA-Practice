#include <bits/stdc++.h>
using namespace std;

// Super sequence means a sequence where if i am given two strings then super sequence is a string which consisits both a and b as the sub sequence of a string ....
// length is simply the lcs of the two stirng + len(a)-common + len(b)-common

int lcs(string a, string b, int n1, int n2, vector<vector<int>> dp){
    if(n1 <= 0 || n2 <= 0) return 0;
    if(dp[n1][n2] != -1) return dp[n1][n2];
    if(a[n1-1] == b[n2-1]) return dp[n1][n2] = 1+lcs(a,b,n1-1,n2-1,dp);

    return dp[n1][n2] =  max(lcs(a,b,n1-1,n2,dp), lcs(a,b,n1,n2-1,dp));
}

int lcsBottomUp(string a, string b){
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));

    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[i].size(); j++){
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }

    for(int i=1; i<dp.size(); i++){
        for(int j=1; j<dp[i].size(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[a.length()][b.length()];
}

int getSuperSequenceLen(string a, string b){
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));

    // int lcsLen = lcs(a,b,a.length(),b.length(),dp);
    int lcsLen = lcsBottomUp(a,b);

    return lcsLen + a.length()-lcsLen + b.length()-lcsLen;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}