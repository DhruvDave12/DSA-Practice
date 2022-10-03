#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int helper(int idx, string input, vector<int> &dp){
        if(idx >= input.length()) return 1;

        if(input[idx] == '0') return dp[idx] = 0;

        int ans = 0;
        for(int i=idx; i<min(idx+2,(int)input.length()); i++){
            if(stoi(input.substr(idx,i-idx+1)) <= 26){
                ans += helper(i+1,input,dp);
            }
        }

        return dp[idx] = ans;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length()+1, -1);
        int ans = helper(0,s,dp);

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}