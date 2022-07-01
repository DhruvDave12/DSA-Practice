#include <bits/stdc++.h>
using namespace std;

// Prefix sum technique helps to find 0 in a subarray
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int vec[], int n)
    {
        for(int i=0; i<n; i++){
            if(vec[i] == 0){
                return true;
            }
        }
        
        map<int,int> mp;
        mp[vec[0]]++;
        for(int i=1; i<n; i++){
            vec[i] = vec[i-1] + vec[i];
            mp[vec[i]]++;
        }
        
        map<int,int> :: iterator itr;
        for(itr=mp.begin(); itr!=mp.end(); itr++){
            if(itr->first == 0 || itr->second > 1){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}