#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

// Top Down way for getting the count of number of times we get sum 
    int solver(vector<int> &arr, int i, int sum, int S2,vector<vector<int>> &dp)
    {
        if (sum == S2)
            return 1;
        if (i >= arr.size())
            return 0;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        if (sum + arr[i] > S2)
            return dp[i][sum] = solver(arr, i + 1, sum, S2, dp);
        
        return dp[i][sum] = solver(arr, i + 1, sum + arr[i], S2, dp) + solver(arr, i + 1, sum, S2, dp);
    }

    int getCount(vector<int> &arr, int diff)
    {
        // we need number of subsets with S1-S2 = diff
        // We know S1+S2 = totalArr

        // Subtract them -> 2S2 = totalArr - diff
        // S2 = (totalArr - diff) / 2
        // Means we need the count of S2 the number of times i get S2 that is the number of times S1-S2 will be equal to diff

        int totalArr = 0;
        for (auto x : arr)
            totalArr += x;

        vector<vector<int>> dp(arr.size() + 1, vector<int>(totalArr + 1, -1));

        if (totalArr- diff < 0 || (totalArr - diff) % 2 == 1)
        {
            return 0;
        }
        int sum = 0;
        int i = 0;
        return solver(arr, i, sum, (totalArr - diff) / 2, dp);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {1, 1, 1, 1, 1};
    int diff = 3;

    Solution s;

    int ans = s.getCount(arr, diff);
    cout << "ANS: " << ans << "\n";
    return 0;
}