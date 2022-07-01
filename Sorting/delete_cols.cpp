#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int ans = 0;
        int maxLen = strs[0].length();

        int k = 0;

        while (k < maxLen)
        {
            for (int i = 0; i < strs.size() - 1; i++)
            {
                if ((strs[i + 1][k] - strs[i][k]) < 0)
                {
                    ans++;
                    break;
                }
            }
            k++;
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