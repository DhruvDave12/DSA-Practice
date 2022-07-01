#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long start = 0;
        long long end = m-1;
        long long ans = INT_MAX;
        while(end < a.size()){
            ans = min(ans, a[end]-a[start]);
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