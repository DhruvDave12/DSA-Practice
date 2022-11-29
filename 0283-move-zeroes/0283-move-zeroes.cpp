class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int limit = nums.size();
        int i = 0;
        
        while(i < limit){
            if(nums[i] == 0){
                auto it = nums.begin()+i;
                nums.erase(it);
                nums.push_back(0);
                limit--;
            } else {
                i++;
            }
        }
    }
};