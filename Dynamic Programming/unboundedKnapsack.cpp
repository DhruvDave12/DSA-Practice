#include <bits/stdc++.h>
using namespace std;

int unboundedKnapSack(vector<int> val, vector<int> wt, int W)
{
    vector<vector<int>> dp(wt.size() + 1, vector<int>(W + 1, -1));
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

    // Simply just where we used to only visit the element once and make decision now we can go
    // if we dont wanna take that element then we will never go back and if we go then we can go back again and take it as many times as we want
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[wt.size()][W];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}