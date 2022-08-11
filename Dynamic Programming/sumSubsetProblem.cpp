#include <bits/stdc++.h>
using namespace std;

// Recursive solution with time complexity exponential
class Solution{   
public:
    bool helper(vector<int> &arr, int sumTill, int n, int targetSum){
        if(n < 0) return false;
        if(targetSum == sumTill) return true;
        
        bool includingExists = helper(arr, sumTill+arr[n], n-1, targetSum);
        bool doesntIncludeExists = helper(arr, sumTill, n-1, targetSum);

        if(includingExists || doesntIncludeExists) return true;

        return false;
    }

    bool isSubsetSum(vector<int> arr, int sum){
        bool ans = helper(arr, 0, arr.size()-1, sum);
        return ans;
    }
};

class Solution2{   
public:
    
    bool isSubsetSum(vector<int> arr, int sum){
        vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum+1));
        
        for(int i=0; i<dp.size(); i++){
            for(int j=0; j<dp[i].size(); j++){
                if(i == 0){
                    dp[i][j] = false;
                } 
                if(j == 0){
                    dp[i][j] = true;
                }
            }
        }

        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[i].size(); j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[arr.size()][sum];
    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    vector<int> arr = {3,34,4,12,5,2};
    int sum = 46;

    // Solution s;

    // bool ans = s.isSubsetSum(arr, sum);

    // if(ans){
    //     cout<<"YES"<<"\n";
    // } else {
    //     cout<<"NO"<<"\n";
    // }

    Solution2 s2;
    bool ans2 = s2.isSubsetSum(arr, sum);
    if(ans2){
        cout<<"YES"<<"\n";
    } else {
        cout<<"NO"<<"\n";
    }
    return 0;
}