#include <bits/stdc++.h>
using namespace std;

    class Solution {
    public:
        // Target sum is same as find the sum with min difference cause at last we are simply just doing partition and finding target diff.
        int solver(vector<int>&nums, int target, vector<vector<int>>&dp, int i, int sum){
            if(sum == target) return 1;
            if(i >= nums.size()) return 0;

            if(dp[i][sum] != -1) return dp[i][sum];

            if(sum + nums[i] > target){
                return dp[i][sum] = solver(nums, target, dp, i+1, sum);
            }

            return dp[i][sum] = solver(nums, target, dp, i+1, sum+nums[i]) + solver(nums, target, dp, i+1, sum);
        }
        
        int findTargetSumWays(vector<int>& nums, int target) {
            int totalArr = 0;
            for(auto it: nums) totalArr += it;

            // S1 + S2 = totalArr
            // S1 - S2 = target

            // S2 = (totalArr - target) / 2
            // We have to find S2

            vector<vector<int>>dp(nums.size()+1, vector<int>(totalArr+1, -1));
            if((totalArr-target) < 0 || (totalArr-target)%2 == 1) return 0;
            int sum = 0;
            int i = 0;
            return solver(nums, (totalArr-target)/2, dp, i, sum);

        }
    };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr = {1,1,1,1,1};
    int target = 3;

    Solution s;
    int ans = s.findTargetSumWays(arr, target);
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}