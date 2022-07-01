#include <bits/stdc++.h>
using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // 2 vector method
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = arr[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], arr[i]);
        }

        rightMax[n-1] = arr[n-1];
        for(int i = n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += min(leftMax[i], rightMax[i]) - arr[i];
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