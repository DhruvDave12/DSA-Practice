#include <bits/stdc++.h>
using namespace std;

// now we need a string b that could be palindrome in this string.
// it is basically LCS OF a and reverse(a);

int lcs(string a, string b){
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
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[a.length()][b.length()];
}   

int lps(string a){
    string b = a;
    reverse(b.begin(), b.end());
    
    int res = lcs(a,b);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    


    return 0;
}