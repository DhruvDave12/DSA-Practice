#include <bits/stdc++.h>
using namespace std;

// this is basic recursion code for the rod cutting problem
int helper(vector<int> len, vector<int> price, int N, int i){
    if(i < 0) return N*price[0];

    int notTaken = helper(len, price, N, i-1);
    int taken = INT_MIN;
    if(i+1 <= N){
        // it is unbounded thats why we have kept i only and not i-1
        taken = price[i] + helper(len, price, N-(i+1), i);
    }

    return max(taken, notTaken);
}

int helperMemoization(vector<int> len, vector<int> price, int N, int i, vector<vector<int>>&dp){
    if(i < 0) return N*price[0];

    if(dp[i][N] != -1) return dp[i][N];

    int notTaken = helper(len, price, N, i-1);
    int taken = INT_MIN;
    if(i+1 <= N){
        // it is unbounded thats why we have kept i only and not i-1
        taken = price[i] + helper(len, price, N-(i+1), i);
    }

    return dp[i][N] = max(taken, notTaken);
}

int helperBottomUP(vector<int>len, vector<int> price, int N){
    // the first N denotes the len.size();
    
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 0;
        }
    }

    for(int i=1; i<dp.size(); i++){
        for(int j=1; j<dp[i].size(); j++){
            if(len[i-1] <= j){
                dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][N];
}
int maxProfitRodCutting(vector<int> len, vector<int> price, int N){
    // int ans = helper(len, price, N, N-1);

    // vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    // int ans = helperMemoization(len, price, N, N-1, dp);

    int ans = helperBottomUP(len,price,N);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> len = {1,2,3,4,5,6,7,8};
    vector<int> price = {1,5,8,9,10,17,17,20};
    int N = 8;   

    int ans = maxProfitRodCutting(len, price, N);
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}