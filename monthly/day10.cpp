#include <bits/stdc++.h>
using namespace std;

// Slow brute force solution working with O(n^2)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        vector<int> possibleAns;
        map<char, bool> mp;

        for(int i=0; i<s.length(); i++){
            int counter = 1;
            mp[s[i]] = true;
            for(int j=i+1; j<s.length(); j++){
                if(mp[s[j]]){
                    break;
                }
                else{
                    mp[s[j]] = true;
                    counter++;
                }
            }
            possibleAns.push_back(counter);
            mp.clear();
        }

        int maxAns = INT_MIN;
        for(int i=0; i<possibleAns.size(); i++){
            maxAns = max(maxAns, possibleAns[i]);
        }

        return maxAns;
    }
};

class Solution1 {
    public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> freq;

        int end = 0, start = 0, ans = 0;
        // abcabcbb
        while(end < s.length()){
            freq[s[end]]++;
            while(freq[s[end]] != 1){
                // here we are removing that element that is causing the freq to increase than 1 using freq map.
                
                freq[s[start]]--;
                start++;
            }
            ans = max(ans, end-start+1);
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