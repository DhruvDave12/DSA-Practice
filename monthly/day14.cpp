#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s[i] != s[s.length() - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        // Brute Force:
        // Recursive Tree ->
        // 1. Decision (Include the character or dont include the character)
        int maxLen = INT_MIN;
        string ans = "";
        map<string, bool> mp;

        for (int i = 0; i < s.length(); i++)
        {
            string t = "";
            t += s[i];
            for (int j = i + 1; j < s.length(); j++)
            {
                t += s[j];
                if (mp.find(t) != mp.end())
                {
                    // we found it inside the map
                    if (mp[t])
                    {
                        if (t.length() > ans.length())
                        {
                            ans = t;
                        }
                    }
                }

                else
                {
                    if (isPalindrome(t))
                    {
                        mp[t] = true;
                        if (t.length() > ans.length())
                        {
                            ans = t;
                        }
                    }
                    else
                    {
                        mp[t] = false;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string ans = s.longestPalindrome("cbbd");

    cout << ans << "\n";
    return 0;
}