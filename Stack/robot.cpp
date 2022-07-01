#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool conditionsMet(char c, int cr, int cc, int n)
    {
        if (c == 'R')
        {
            if (cc < n - 1)
            {
                return true;
            }
            // return false;
        }
        else if (c == 'L')
        {
            if (cc > 0)
            {
                return true;
            }
            // return false;
        }
        else if (c == 'U')
        {
            if (cr > 0)
            {
                return true;
            }
            // return false;
        }
        else if (c == 'D')
        {
            if (cr < n - 1)
            {
                return true;
            }
            // return false;
        }
        return false;
    }

    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        vector<int> ans;
        int cr = startPos[0];
        int cc = startPos[1];
        // stack<pair<char, int>> st;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int j = i;
            while (conditionsMet(s[j], cr, cc, n))
            {
                cout<<s[j];
                count++;
                if (s[j] == 'L')
                {
                    cc--;
                }
                else if (s[j] == 'R')
                {
                    cc++;
                }
                else if (s[j] == 'U')
                {
                    cr--;
                }
                else if (s[j] == 'D')
                {
                    cr++;
                }
                j++;
            }
            ans.push_back(count);
            count = 0;
            cr = startPos[0];
            cc = startPos[1];
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vec = {0, 1};
    int n = 3;
    string s = "RRDDLU";

    Solution sol;
    vector<int> ans = sol.executeInstructions(n, vec, s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}