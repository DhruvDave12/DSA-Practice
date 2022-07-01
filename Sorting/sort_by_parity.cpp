#include <bits/stdc++.h>
using namespace std;

// O(NLOGN)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        int evenIdx = 0;
        int oddIdx = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                mp.insert({evenIdx, nums[i]});
                evenIdx += 2;
            } else {
                mp.insert({oddIdx, nums[i]});
                oddIdx += 2;
            }
        }

        map<int,int> :: iterator itr;
        for(itr = mp.begin(); itr != mp.end(); itr++){
            if(itr->first % 2 == 0){
                ans.push_back(itr->second);
            }
        }
        for(itr = mp.begin(); itr != mp.end(); itr++){
            if(itr->first % 2 != 0){
                ans.push_back(itr->second);
            }
        }

        return ans;
    }
};

class Solution1 {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        
        int swapper=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                swap(nums[i], nums[swapper]);
                swapper++;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    return 0;
}