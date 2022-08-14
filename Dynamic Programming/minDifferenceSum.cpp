#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(vector<int>&arr, int totalSum, int sum, int &res, int i){
        if(i >= arr.size()) return;

        res = min(res, abs((totalSum-sum)-sum));
        
        helper(arr, totalSum, sum+arr[i], res, i+1);
        helper(arr, totalSum, sum, res, i+1);
    }
    int minimumDifference(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++) totalSum+=nums[i];
        int res = INT_MAX;
        int i = 0;
        int sum = 0;

        helper(nums, totalSum, sum, res, i);

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr = {76,8,45,20,74,84,28,1};

    Solution s;
    int ans = s.minimumDifference(arr);

    cout<<"ANS: "<<ans<<"\n"; 
    return 0;
}