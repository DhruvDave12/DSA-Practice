#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void reverseVector(vector<int> &nums, int index1){
        for(int i=index1; i<(nums.size()-index1) / 2; i++){
            int temp = nums[i];
            nums[i] = nums[nums.size()-index1-i];
            nums[nums.size()-index1-i] = temp;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int swapIndex = -1;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i-1] <= nums[i]){
                swapIndex = i+1;
                break;
            }
        }    

        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] > nums[swapIndex]){
                swap(nums[i], nums[swapIndex]);
                break;
            }
        }
        reverseVector(nums, swapIndex+1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}