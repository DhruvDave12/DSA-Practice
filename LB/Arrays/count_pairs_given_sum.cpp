#include <bits/stdc++.h>
using namespace std;

// can do with hashing
int countPairs(vector<int> nums, int k){
    map<int,int> mp;

    int count = 0;
    for(int i=0; i<nums.size(); i++){
        if(mp[k-nums[i]] > 0){
            count += mp[k-nums[i]];
            mp[k-nums[i]] ++;
        }
        mp[nums[i]]++;
    }

    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {1, 5, 7, 1, 4, 3, 2, 4, 2};
    cout<<countPairs(vec, 6)<<"\n";
    return 0;
}