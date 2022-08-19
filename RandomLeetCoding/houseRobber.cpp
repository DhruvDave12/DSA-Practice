#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int res = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        vector<int> prevIdx;
        while(!pq.empty()){
            int currIdx = pq.top().second;
            bool flag = false;
            for(int i=0; i<prevIdx.size(); i++){
                if(abs(prevIdx[i]-currIdx) == 1) {
                    flag = true;
                    break;
                };
            }
            if(!flag){
                res += pq.top().first;
                prevIdx.push_back(currIdx);
            }
            pq.pop();
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