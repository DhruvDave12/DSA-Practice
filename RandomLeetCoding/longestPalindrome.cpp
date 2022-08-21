#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        if(mp.size() == 1){
            return mp.begin()->second;
        }
        vector<int> vec;
        for(auto it: mp){
            vec.push_back(it.second);
        }

        sort(vec.begin(), vec.end());
        int ans = 1;
        bool flag = false;
        for(int i=1; i<vec.size(); i++){
            if(vec[i]%2==0){
                ans += vec[i];
            } else {
                flag = true;
                ans += vec[i]-1;
            };
        }

        return flag ? ans+1 : ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}