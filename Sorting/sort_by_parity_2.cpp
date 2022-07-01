#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        stack<int> st;

        for(int i=0; i<nums.size(); i++){
            if(((i%2 == 0) && (nums[i]%2 != 0)) || ((i%2 != 0) && (nums[i]%2 == 0))){
                // means if swap condition occurs
                if(i%2==0){
                    if(!st.empty() && st.top()%2 != 0){
                        swap(nums[i], nums[st.top()]);
                        st.pop();
                    }
                    else {
                        st.push(i);
                    }
                }
                else{
                    if(!st.empty() && st.top()%2 == 0){
                        swap(nums[i], nums[st.top()]);
                        st.pop();
                    }
                    else{
                        st.push(i);
                    }
                }
            }
        }
        return nums;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums = {4,2,5,7};
    Solution s;
    s.sortArrayByParityII(nums);
    return 0;
}