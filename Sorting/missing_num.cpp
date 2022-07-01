#include <bits/stdc++.h>
using namespace std;

// O(nlogn) -> Normal Sort
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i){
                return i;
            }
        }
        return nums.size();
    }
};

// O(nlogn) -> Priority Queue
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {

        priority_queue<int, vector<int>, greater<int>> pqMin;
        for(int i=0; i<nums.size(); i++){
            pqMin.push(nums[i]);
        }   

        for(int i=0; i<nums.size(); i++){
            if(pqMin.top() != i){
                return i;
            }
            pqMin.pop();
        }
        return nums.size();
    }
};

// O(n) -> check the sum of numbers
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int sumArr = 0;
        for(int i=0; i<nums.size(); i++){
            sumArr += nums[i];
        }

        int reqSum = (nums.size() * (nums.size() + 1)) / 2;

        return reqSum - sumArr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution2 s;
    vector<int> nums = {1, 2, 3};

    s.missingNumber(nums);
    return 0;
}