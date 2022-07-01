#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // [[1,3], [2,6], [8, 10], [15, 18]]
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        queue<pair<int,int>> q;
        q.push({intervals[0][0], intervals[0][1]});

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][1] <= q.back().second && intervals[i][0] <= q.back().second){
                // dont push anything just continue;
                continue;
            }
            else if (intervals[i][0] <= q.back().second){
                // means we can edit the second unit
                q.back().second = intervals[i][1];
            }
            else if(intervals[i][0] > q.back().second){
                // here we get another interval so we insert it inside the stack
                q.push({intervals[i][0], intervals[i][1]});
            }
        }
         
         while(!q.empty()){
            vector<int> v;
            v.push_back(q.front().first);
            v.push_back(q.front().second);
            ans.push_back(v);
            q.pop();
         }

         return ans;
    }
};

// Same logic more efficient
class Solution2 {
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
        vector<vector<int>>vec;
        vec.push_back(intervals[0]);
        int k = 0;
        for(int i=1;i<intervals.size();i++)
        {
            if(vec[k][1]>=intervals[i][0])
            {
                vec[k][1]=intervals[i][1]>vec[k][1]?intervals[i][1]:vec[k][1];
            }
            else
            {
                k++;
                vec.push_back(intervals[i]);
            }
        }
        return vec;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> v = {{1,4}, {2,3}};
    Solution s;
    vector<vector<int>> ans = s.merge(v);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }

    return 0;
}