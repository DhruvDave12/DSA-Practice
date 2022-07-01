#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class comparator
    {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            // first condition is min heap and second is decreasing order
            if (a.first != b.first)
            {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        // heap max
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> q;

        for (auto i = m.begin(); i != m.end(); i++)
        {
            q.push({i->second, i->first});
        }
        vector<int> ans;
        while (!q.empty())
        {

            int x = q.top().first;
            while (x > 0)
            {
                ans.push_back(q.top().second);
                x--;
            }
            q.pop();
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {8, -8, 2, -8, -5, -3};
    s.frequencySort(nums);
    return 0;
}