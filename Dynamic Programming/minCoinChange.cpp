#include <bits/stdc++.h>
using namespace std;

int minCoinsReq(vector<int> &coins, int sum){
    vector<vector<int>> dp(coins.size()+1, vector<int>(sum+1));
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[i].size(); j++){
            if(i == 0){
                dp[i][j] = INT_MAX-1;
            }
            if(j == 0){
                dp[i][j] = 0;
            }
        }
    }

    // here we have to initialize the second row also like this

    for(int j=1; j<dp[1].size(); j++){
        if(j % coins[0] == 0){
            dp[1][j] = j/coins[0];
        } else dp[1][j] = INT_MAX-1;
    }

    for(int i=2; i<dp.size(); i++){
        for(int j=1; j<dp[i].size(); j++){
            if(coins[i-1] <= j){
                // if we can include the coin
                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            } else{
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
    
    vector<int> coins = {1,4,5};

    int sum = 5;

    int ans = minCoinsReq(coins, sum);
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}