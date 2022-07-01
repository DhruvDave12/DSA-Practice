#include <bits/stdc++.h>
using namespace std;

// Longest subarray with sum s

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        int n,s;
        cin>>n>>s;

        vector<int> arr(n);
        int oldSum = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            oldSum += arr[i];
        }

        if(oldSum < s){
            cout<<-1<<"\n";
            continue;
        }
        
        int start = 0, end = 0, maxSubarray = INT_MIN;
        int sum = 0;
        while(end < n) {
            sum += arr[end];
            if(sum < s){
                end++;
            }
            if(sum == s){
                maxSubarray = max(maxSubarray, end-start+1);
                end++;
            }
            else if(sum > s){
                while(sum > s){
                    sum -= arr[start];
                    start++;
                }
                if(sum == s){
                    maxSubarray = max(maxSubarray, end-start+1);
                }
                end++;
            }
        }

        cout<<n-maxSubarray<<"\n";
    }
    return 0;
}