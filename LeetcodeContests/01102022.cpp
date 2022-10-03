#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool allSame(vector<int> freq)
    {

        int same;

        // get first non-zero element
        int i;
        for (i = 0; i < freq.size(); i++)
        {
            if (freq[i] > 0)
            {
                same = freq[i];
                break;
            }
        }

        // check equality of each element with variable same
        for (int j = i + 1; j < freq.size(); j++)
            if (freq[j] > 0 && freq[j] != same)
                return false;

        return true;
    }

    bool equalFrequency(string word)
    {
        vector<int> vec(26, 0);
        for (int i = 0; i < word.length(); i++)
        {
            vec[word[i] - 'a']++;
        }

        if (allSame(vec))
            return false;

        // now we will decrease the count of each letter and then check
        for (int i = 0; i < vec.size(); i++)
        {
            vec[i]--;
            if (allSame(vec))
                return true;
            vec[i]++;
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}