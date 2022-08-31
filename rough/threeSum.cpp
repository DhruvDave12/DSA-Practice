#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int temp = 0;
        sort(nums.begin(), nums.end());
        map<int,int> mp;
        set<vector<int>> st;

        for(int i=0; i<nums.size(); i++){
            temp = 0-nums[i];
            mp.clear();
            int lo = i+1;
            int hi = nums.size()-1;

            while(lo <= hi){
                    if(nums[lo] + nums[hi] == temp){
                        if(mp.count(lo) == 0 && mp.count(hi) == 0 && mp.count(i) == 0){
                            vector<int> vec;
                            vec.push_back(nums[i]);
                            vec.push_back(nums[lo]);
                            vec.push_back(nums[hi]);

                            st.insert(vec);
                            hi--;
                            lo++;
                        } else break;
                    } 
                if(nums[lo] + nums[hi] < temp) lo++;
                if(nums[lo] + nums[hi] > temp) hi--;
            }
        }

        vector<vector<int>> res;

        for(auto it: st){
            res.push_back(it);
        }

        return res;

    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}