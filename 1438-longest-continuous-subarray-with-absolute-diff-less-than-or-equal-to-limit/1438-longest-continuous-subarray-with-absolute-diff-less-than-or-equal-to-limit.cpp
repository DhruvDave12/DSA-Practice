class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> mt;
        int j = 0, ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            mt.insert(nums[i]);
            
            if(*mt.rbegin()-*mt.begin() > limit){
                mt.erase(mt.lower_bound(nums[j++]));
            }
            
            ans = max(ans,i-j+1);
        }
        
        return ans;
    }
};