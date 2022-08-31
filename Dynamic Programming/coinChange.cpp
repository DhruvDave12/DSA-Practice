#include <bits/stdc++.h>
using namespace std;

// simple recursion but exponential complexity
int helper(vector<int> coins, int sum, int i){
    if(i < 0) return 0;
    if(sum < 0) return 0;
    if(sum == 0) return 1;

    // int notTake = helper(coins, sum, i-1);
    // int take = INT_MIN;
    // if(coins[i] <= sum){
    //     take = helper(coins, sum-coins[i], i);
    // } 
    return helper(coins, sum, i-1) + helper(coins, sum-coins[i], i);
}

int helperMemoization(vector<int> coins, int sum, int i, vector<vector<int>> &dp){
    if(i < 0) return 0;
    if(sum == 0) return 1;
    if(dp[i][sum] != -1) return dp[i][sum];

    int notTake = helperMemoization(coins, sum, i-1, dp);
    int take = INT_MIN;
    if(coins[i] <= sum){
        take = helperMemoization(coins, sum-coins[i], i, dp);
        return dp[i][sum] = take+notTake;
    } 
    return dp[i][sum] = notTake;
}

int numberOfWays(vector<int> coins, int sum){
    int ans = helper(coins, sum, coins.size()-1);
    // vector<vector<int>> dp(coins.size()+1, vector<int>(sum+1, -1));
    // int ans = helperMemoization(coins, sum, coins.size()-1, dp);
    return ans;
}

class Solution {
  public:
    long long int helper(int S[], int m, int n, int dp[1001][1001]){
        if(m < 0) return 0;
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = helper(S,m,n-S[m], dp) + helper(S,m-1,n,dp);
    }
    long long int count(int S[], int m, int n) {
        int dp[1001][1001];
        for(int i=0; i<1001; i++){
            for(int j=0; j<1001; j++){
                dp[i][j] = -1;
            }
        }

        long long int ans = helper(S,m,n,dp);
        return ans;
    }
};

int helperBottomUp(vector<int> &coins, int sum){
    vector<vector<int>> dp(coins.size(), vector<int>(sum+1, 0));

    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[i].size(); j++){
            if(i == 0){
                dp[i][j] = 0; 
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }

    for(int i=1; i<dp.size(); i++){
        for(int j=1; j<dp.size(); j++){
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[coins.size()-1][sum];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> coins = {1,2,3};
    int sum = 4;

    // int ans = numberOfWays(coins, sum);
    // cout<<"ANS: "<<ans<<"\n";

   
    int ans = helperBottomUp(coins, sum);
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}