#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOverlapping(int start1, int end1, int start2, int end2)
    {
        if (start1 < end2 && start2 < end1)
        {
            return true;
        }
        return false;
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> res;

        for(int i=0; i<firstList.size(); i++){
            for(int j=0; j<secondList.size(); j++){
                int start1 =  firstList[i][0];
                int end1 = firstList[i][1];

                int start2 = secondList[j][0];
                int end2 = secondList[j][1];

                if(isOverlapping(start1, end1, start2, end2)){
                    int startMax = max(start1, start2);
                    int endMin = min(end1, end2);
                    res.push_back({startMax, endMin});
                }
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