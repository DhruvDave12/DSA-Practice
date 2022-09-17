#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // recursive with TLE
    int solver(vector<int>& nums, vector<int>& multipliers, int start, int end, int i, int old){
        
        if(start >= nums.size() || end < 0 || i >= multipliers.size()) return 0;

        int maxIncludingStart = solver(nums,multipliers,start+1,end, i+1,old);
        int maxIncludingEnd = solver(nums,multipliers,start,end-1, i+1,old);
        
        int x = nums[start]*multipliers[i] + maxIncludingStart;
        int y = nums[end]*multipliers[i] + maxIncludingEnd;
        
        return max(x,y);
    } 

    // DP without TLE
    int solverDP(vector<int>& nums, vector<int> &multiplier, int start, int i, vector<vector<int>> &dp){
        if(i == multiplier.size()) return 0;
        if(dp[start][i] != INT_MIN) return dp[start][i];

        int includingStart = nums[start]*multiplier[i] + solverDP(nums,multiplier,start+1,i+1,dp);
        // the way we are relating (n-1)-(i-start) is the main thing for this. Very useful when we have to work with start and end
        int includingEnd = nums[(nums.size()-1)-(i-start)]*multiplier[i] + solverDP(nums,multiplier,start,i+1,dp);

        return dp[start][i] = max(includingStart,includingEnd);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // int ans = solver(nums,multipliers,0,nums.size()-1,0,0);

        vector<vector<int>> dp (multipliers.size()+1, vector<int>(multipliers.size()+1, INT_MIN));
        int ans = solverDP(nums,multipliers,0,0,dp);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}