#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                nums[i] = -1 * nums[i];
            }
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }

        return nums;
    }
};

class Solution1
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left;
        int right;
        int start;
        bool found = false;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                start = i;
                found = true;
                break;
            }
        }

        if(found && start == 0){
            // just square and return
            for(int i=0; i<nums.size(); i++){
                ans.push_back(nums[i]);
            }
        }

        else if(!found || start == nums.size() - 1){
            // square and return in opposite order
            for(int i=nums.size()-1; i>=0; i--){
                ans.push_back(nums[i]);
            }
        }
        
        else {
            left = start-1;
            right = start+1;
            
            while(left >= 0 && right < nums.size()){
                if(abs(nums[left]) < abs(nums[right])){
                    ans.push_back(nums[left]);
                    left--;
                }
                else if(abs(nums[left]) > abs(nums[right])){
                    ans.push_back(nums[right]);
                    right++;
                }
                else {
                    ans.push_back(nums[left]);
                    ans.push_back(nums[right]);
                    left--;
                    right++;
                }
            }
        }

        for(int i=0; i<ans.size(); i++){
            ans[i] = ans[i] * ans[i];
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