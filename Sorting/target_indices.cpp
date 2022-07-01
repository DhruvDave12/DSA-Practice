#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
       
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans = {};
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                ans.push_back(i);
            }
        }

        return ans;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    vector<int> nums = {1,2,3,4,3,4,2};

    s.targetIndices(nums, 3);
    return 0;
}