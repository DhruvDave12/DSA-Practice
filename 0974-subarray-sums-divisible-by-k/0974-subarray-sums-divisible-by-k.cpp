class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // subarray and sum problem -> Hash Table, Prefix Sum
        map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int res = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            
            int rem = sum % k;
            // negative remainders handled
            if(rem < 0) rem += k;
            
            if(mp.find(rem) != mp.end()){
                res += mp[rem];
            }
            
            mp[rem]++;
        }
        
        return res;
    }
};