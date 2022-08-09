#include <bits/stdc++.h>
using namespace std;
#include <sys/time.h>
typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int knapsack01(vector<int> &wt, vector<int>&val, int W, int n, vector<vector<int>>&dp){
    if(n==0 || W == 0) return 0;

    if(dp[n][W] != -1){
        return dp[n][W];
    }
    
    if(wt[n-1] <= W){
        return dp[n][W] = max(val[n-1] + knapsack01(wt,val,W-wt[n-1],n-1,dp), knapsack01(wt,val,W,n-1, dp));
    } 
    else{
        return dp[n][W] = knapsack01(wt,val,W,n-1,dp);
    }
}

int knapSackTopDown(vector<int>&val, vector<int>&wt, int W, int N){
    vector<vector<int>> dp(N+1, vector<int>(W+1,-1));

    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[i].size(); j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<dp.size(); i++){
        for(int j=1; j<dp[i].size(); j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][W];
}

int main()
{
    timestamp_t t0 = get_timestamp();

    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,19};
    int W = 7;

    vector<vector<int>> dp(wt.size()+1, vector<int>(W+1, -1));

    int wtTaken = 0, maxProfit = INT_MIN;
    int ans = knapsack01(wt,val,W,wt.size(), dp);
    cout<<"MAX PROFIT IS: "<<ans<<"\n";


    int ansTopDown = knapSackTopDown(val, wt, W, wt.size());
    cout<<"TOP DOWN ANS: "<<ansTopDown<<"\n";

    timestamp_t t1 = get_timestamp();
    double secs = (t1 - t0);
    cout << "Time taken by program is : " << fixed
         << secs << setprecision(5);
    cout << " sec " << endl;
    return 0;
}