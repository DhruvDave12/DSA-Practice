#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        // first store all the same occuring pairs in the res vector
        vector<int> res;
        int counter = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
                counter++;
            else
            {
                res.push_back(counter);
                counter = 1;
            }
        }

        // now we have to check the min like i have
        // 00 111  so res has 2 3 so min is 2 means we can have 0011 pair
        int ans = 0;
        for(int i=0; i<res.size()-1; i++){
            ans += min(res[i], res[i+1]);
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