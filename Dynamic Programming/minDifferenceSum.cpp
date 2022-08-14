#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
        
//     }
// };

class Solution{
  public:
    
    void fillDP(int arr[], int n, vector<vector<bool>> &dp){
        for(int i=0;i<dp.size(); i++){
            for(int j=0; j<dp[i].size(); j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }

        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[i].size(); j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

	int minDifference(int arr[], int n)  { 
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += arr[i];

        vector<vector<bool>> dp(n+1, vector<bool>(totalSum+1,false));

        fillDP(arr, n, dp);
        int res = INT_MAX;
        for(int i=0; i<dp[n].size(); i++){
            if(dp[n][i] && i <= totalSum/2){
                res = min(res, (totalSum-(2*i)));
            }
        }
        return res;
    } 
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[] = {1,2,7};
    int n = 3;

    Solution s;
    int ans = s.minDifference(arr, n);

    cout<<"ANS: "<<ans<<"\n"; 
    return 0;
}