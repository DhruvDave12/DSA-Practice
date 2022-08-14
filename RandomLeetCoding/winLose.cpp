#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillMap(vector<vector<int>>&matches, map<int,pair<int,int>> &mp){
        for(int i=0; i<matches.size(); i++){
            mp[matches[i][0]].first = 0;
            mp[matches[i][1]].second = 0;
        }
        for(int i=0; i<matches.size(); i++){
            mp[matches[i][0]].first++;
            mp[matches[i][1]].second++;
        }
    }   
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>> mp;
        fillMap(matches, mp);

        vector<int> vec1, vec2;
        map<int,pair<int,int>> :: iterator it;

        for(it=mp.begin(); it!=mp.end(); it++){
            if(it->second.second == 0){
                vec1.push_back(it->first);
            }
            if(it->second.second == 1){
                vec2.push_back(it->first);
            }
        }

        vector<vector<int>> res;
        res.push_back(vec1);
        res.push_back(vec2);

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}