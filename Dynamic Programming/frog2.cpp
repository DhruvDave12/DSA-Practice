#include <bits/stdc++.h>
using namespace std;

int solver(vector<int> &height, int k)
{
    int n = height.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int x;
        if(i < k){
            x = i-(i%k);
        } else {
            x = i-k;
        }
        for (int j = x; j < i; j++)
        {
            int cost = abs(height[i] - height[j]);
            dp[i] = min(dp[i], dp[j]+cost);
        }
    }

    // for(int i=0; i<dp.size(); i++){
    //     cout<<dp[i]<<" ";
    // }
    return dp[height.size() - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];

    int ans = solver(height, k);

    cout << ans << "\n";
    return 0;
}