#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
    int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        int m=1e9+7;
        for(int i=0; i<dp.size(); i++){
            for(int j=0; j<dp[i].size(); j++){
                if(i == 0){
                    // if no elements then we can not get any subset with sum 'K'
                    dp[i][j] = 0;
                }
                if(j == 0){
                    // if we have sum = 0 then we will always get a subset no matter how many elements
                    dp[i][j] = 1;
                }
            }
        } 
           
        for(int i=1; i<=n; i++){
                for(int j=0; j<= sum; j++){
                    if(arr[i-1] <= j){
                        // if the element is smaller than the sum 'j' then only we can have an option to include else we will exclude it only
                        dp[i][j] = dp[i-1][j-arr[i-1]]%m + dp[i-1][j]%m;
                    } else {
                        dp[i][j] = dp[i-1][j]%m;
                    }
                }
            }

            return dp[n][sum]%m;
    }
	  
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = 6;

    Solution s;
    int ans = s.perfectSum(arr, n, sum);

    cout<<ans<<"\n";
    return 0;
}