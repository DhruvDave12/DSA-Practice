#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int start = 0;
        int end = numbers.size()-1;

        while(end > start){
            int sum = numbers[end] + numbers[start];

            if(sum > target){
                end--;
            }
            else if(sum < target){
                start++;
            }
            else if(sum == target){
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
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