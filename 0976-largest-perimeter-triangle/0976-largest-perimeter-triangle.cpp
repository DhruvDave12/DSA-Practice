class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        
        for(int i=0; i<=nums.size()-3; i++){
            if(nums[i+1]+nums[i+2] > nums[i] && (long long)nums[i+1]*(long long)nums[i+2] != 0) {
                return nums[i+1]+nums[i+2]+nums[i];
            }
        }
        
        return 0;
    }
};