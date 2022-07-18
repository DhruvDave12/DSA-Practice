#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(vector<int> &cost, int i){
        if(i >= cost.size()){
            return 0;
        }
        return cost[i] + min(helper(cost,i+1), helper(cost,i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int ans = helper(cost,0);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {1,100,1,1,1,100,1,1,100,1};
    Solution s;
    int ans = s.minCostClimbingStairs(vec);
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}