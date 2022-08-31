#include <bits/stdc++.h>
using namespace std;
#define int long long

int minHeight(vector<int>&height){
    // we will use pull dp in this
    vector<int> dp(height.size(), 0);
    // int ans = 0;
    for(int i=1; i<height.size(); i++){
        // if i am at i=1 then i must have come from i=i-1 or i=i-2
        if(i == 1){
            int cost = abs(height[i]-height[i-1]);
            dp[i] = cost;
        }
        else{
            int cost1 = abs(height[i]-height[i-1]);
            int cost2 = abs(height[i]-height[i-2]);
            dp[i] = min(cost1 + dp[i-1], cost2 + dp[i-2]);
        }

    }
    
    return dp[height.size()-1];
}   
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> height(n);

    for(int i=0; i<n; i++) cin>>height[i];
    vector<int> dp(n);
    // int sum = 0;
    int ans = minHeight(height);

    cout<<ans<<"\n";
    // cout<<"SUM: "<<sum<<"\n";
    return 0;
}