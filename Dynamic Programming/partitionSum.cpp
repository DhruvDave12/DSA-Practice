#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
class Solution
{
public:

    bool solver(int N, int arr[], int sum, int totalSum){
        if(N < 0) return false;

        if(totalSum == 2*sum) return true;

        bool including = solver(N-1, arr, sum + arr[N], totalSum);
        bool excluding = solver(N-1, arr, sum, totalSum);

        if(including or excluding) return true;

        return false;
    }

    bool equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for(int i=0; i<N; i++){
            totalSum += arr[i];
        }
        int sum = 0;
        bool ans = solver(N-1, arr, sum, totalSum);

        return ans;
    }
};

class Solution2
{
public:

    // sumSubset Problem
    bool solver(int N, int arr[], int sum, vector<vector<bool>> &dp){
        if(N < 0) return false;

        if(sum == 0) return true;
        if(N == 0 && sum != 0) return false;

        if(dp[N][sum]){
            return true;
        }
        
        if(arr[N] > sum){
            return solver(N-1, arr, sum, dp);
        }

        return dp[N][sum] = solver(N-1, arr, sum-arr[N],dp) or solver(N-1, arr, sum, dp);
    }

    bool equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for(int i=0; i<N; i++) totalSum += arr[i];

        if(totalSum % 2 != 0) return false;

        vector<vector<bool>> dp(N+1, vector<bool>(totalSum+1, false));
        bool ans = solver(N, arr, totalSum/2, dp);

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {1,6,11,6};
    int N = 4;

    Solution s;
    
    bool ans = s.equalPartition(N, arr);

    ans ? cout<<"YES"<<"\n" : cout<<"NO"<<"\n";
    return 0;
}