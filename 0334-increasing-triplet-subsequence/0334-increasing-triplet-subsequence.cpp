class Solution {
public:
    
//     int solver(vector<int> &nums, vector<vector<int>> &dp, int idx, int prev_idx){
//         if(idx >= nums.size()) return 0;
        
//         if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        
//         int not_taken = solver(nums,dp,idx+1,prev_idx);
        
//         int taken = INT_MIN;
//         if(prev_idx == -1 || nums[idx] > nums[prev_idx]){
//             taken = 1 + solver(nums,dp,idx+1,idx);
//         }
        
//         return dp[idx][prev_idx+1] = max(taken,not_taken);
//     }
    
    bool increasingTriplet(vector<int>& nums) {
     
//         int n = nums.size();
        
//         vector<vector<int>> dp (n+1, vector<int>(n+1,-1));
//         int ans = solver(nums,dp,0,-1);
        
//         if(ans >= 3) return true;
//         return false;
        // we will follow the O(N) solution 
        // for every index store the max and min
        vector<int> left_min(nums.size(), INT_MAX);
        left_min[0] = nums[0];
        
        
        vector<int> right_max(nums.size(), INT_MIN);
        right_max[nums.size()-1] = nums[nums.size()-1];
        for(int i=1; i<left_min.size(); i++){
            left_min[i] = min(left_min[i-1], nums[i]);
        }
        
        for(int i=nums.size()-2; i>=0; i--){
            right_max[i] = max(nums[i], right_max[i+1]);
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > left_min[i] && nums[i] < right_max[i]){
                return true;
            }
        }
        
        return false;
    
    }
};