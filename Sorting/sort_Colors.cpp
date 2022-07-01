#include <bits/stdc++.h>
using namespace std;

// Sorting of 0,1 and 2's is done using Dutch National Flag problem
// Here we have low mid high and divivded in ranges where left most range handles 0 mid range handles 1 and right most range handles 2

// O(N)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // we check the mid
        // if element at mid is 0 we swap is with low and increment both
        // if element is 1 we keep in mid and increment just the mid
        // if element is 2 we swap it with high and decrement high and iterator i

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }

        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(nums);

    return 0;
}