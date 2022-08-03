#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<string, pair<int,int>> mp;
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        for(int i=0; i<list1.size(); i++){
            mp[list1[i]].first ++;
            mp[list1[i]].second = i;
        }
        
        for(int j=0; j<list2.size(); j++){
            mp[list2[j]].first ++;
            mp[list2[j]].second += j;
        }
        
        vector<string> res;
        map<string, pair<int,int>> :: iterator itr;
        int minIdx = INT_MAX;
        for(itr=mp.begin(); itr != mp.end(); itr++){
            if(itr->second.first > 1){
                minIdx = min(minIdx, itr->second.second);
            }
        }

        for(itr = mp.begin(); itr != mp.end(); itr++){
            if(itr->second.first > 1 && itr->second.second == minIdx){
                res.push_back(itr->first);
            }
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}