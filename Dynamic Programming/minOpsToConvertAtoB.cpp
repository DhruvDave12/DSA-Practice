#include <bits/stdc++.h>
using namespace std;

// heap
// pea

int lcsLong(string a, string b){
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, -1));
    // int res = INT_MIN;
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[i].size(); j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<dp.size(); i++){
        for(int j=1; j<dp[i].size(); j++){
            if(a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                // res = max(res,dp[i][j]);
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // dp[i][j] = 0;
            }
        }
    }

    return dp[a.length()][b.length()];
}

int minOps(string a, string b){
    int len = lcsLong(a,b);  
    return (a.length()-len) + (b.length()-len);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}