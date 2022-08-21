#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // map<int, pair<int,set<int>>> mp;
    // bool containsNearbyDuplicate(vector<int>& nums, int k) {
    //     for(int i=0; i<nums.size(); i++){
    //         mp[nums[i]].first++;
    //         mp[nums[i]].second.insert(i);
    //     }

    //     for(auto it: mp){
    //         if(it.second.first > 1){
    //             int prev = -1;
    //             for(auto itr: it.second.second){
    //                 if(prev == -1){
    //                     prev = itr;
    //                 }
    //                 else {
    //                     if(abs(itr-prev) <= k) return true;
    //                     prev = itr;
    //                 }
    //             }
    //         }
    //     }

    //     return false;
    // }

    // bool containsNearbyDuplicate(vector<int>&nums, int k){
    //     vector<pair<int,int>> vec;
    //     for(int i=0; i<nums.size(); i++){
    //         vec.push_back({nums[i],i});
    //     }
    //     sort(vec.begin(), vec.end());

    //     for(int i=0; i<vec.size()-1; i++){
    //         int x = vec[i].first;
    //         int y = vec[i+1].first;
    //         if(x == y){
    //             if(abs(vec[i].second - vec[i+1].second) <= k) return true;
    //         }
    //     }

    //     return false;
    // }

    bool containsNearbyDuplicate(vector<int>&nums, int k){
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}