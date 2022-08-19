#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //  1 2 3 3 4 4 5 5

    /*
        1: 1
        2: 1
        3: 2
        4: 2
        5: 2
        6: 2
    */

    bool isPossible(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> vec;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            int curr = nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] - curr == 1 && mp[nums[j]] > 0){
                    count++;
                    curr = nums[j];
                    vec.push_back(nums[j]);
                }
            }
            if(count >= 3){
                for(int k=0; k<vec.size(); k++){
                    if(mp[vec[k]] > 0){
                        mp[vec[k]]--;
                    }
                }
            }
            vec.clear();

        }

        for(auto it: mp){
            if(it.second > 0) return false;
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}