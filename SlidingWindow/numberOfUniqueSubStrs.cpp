#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3;
        map<char, int> mp;
        int count = 0;
        
        for(int i=0; i<k; i++){
            mp[s[i]]++;
        }
        if(mp.size() == k) count++;

        for(int i=k; i<s.length(); i++){
            mp[s[i-k]]--;
            if(mp[s[i-k]] == 0){
                mp.erase(s[i-k]);
            }
            mp[s[i]]++;
            if(mp.size() == k) {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}