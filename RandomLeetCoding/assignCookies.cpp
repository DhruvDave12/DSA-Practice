#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        map<int,int> mp;
        vector<int> unusedCookie;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        // for(int i=0 ;i<s.size(); i++){
        //     auto it = lower_bound(g.begin(), g.end(), s[i]);
        //     int idx = it-g.begin();
        //     if(g[idx] == s[i]){
        //         if(mp.count(idx) == 0){
        //             ans++;
        //             mp[idx] = i;
        //         }else {
        //             unusedCookie.push_back(s[i]);
        //         }
        //     } else {
        //         if(idx > 0){
        //             if(mp.count(idx-1) == 0){
        //                 ans++;
        //                 mp[idx-1] = i;
        //             } else {
        //                 unusedCookie.push_back(s[i]);
        //             }
        //         }
        //     }
        // }

        for(int i=0; i<g.size(); i++){
            auto it = lower_bound(s.begin(), s.end(), g[i]);
            if(it != s.end()){
                int idx = it-s.begin();
                ans++;
                s.erase(it);
            }
        }

        // for(int i=0; i<g.size(); i++){
        //     if(mp.count(i) == 0){
        //         // now assign a cookie from unused cookie
        //         int eleToSatisfy = g[i];
        //         auto it = lower_bound(unusedCookie.begin(), unusedCookie.end(), eleToSatisfy);
        //         if(it != unusedCookie.end()){
        //             ans++;
        //             unusedCookie.erase(it);
        //         }
        //     }
        // }

        
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}