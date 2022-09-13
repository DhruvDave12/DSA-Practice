#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // if(n==0 || m==0) return 0;

        // if(S1[n-1] == S2[m-1]) return 1 + longestCommonSubstr(S1,S2,n-1,m-1);

        // return longestCommonSubstr(S1,S2,n-1,m) + longestCommonSubstr(S1,S2,n,m-1);

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int result = 0;
        for(int i=0;i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0) dp[i][j] = 0;
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    result = max(result,dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return result;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S1 = "ABCDEFGH";
    string S2 = "XYEFGHPQ";

    int ans = Solution().longestCommonSubstr(S1,S2,S1.size(),S2.size());

    cout<<"ANS: "<<ans<<"\n";
    return 0;
}