#include <bits/stdc++.h>
using namespace std;

void getVowelPermutation(int n, string s, int i, int &ans)
{
    if (s.length() == n)
    {
        ans = ans + 1;
        s = "";
        i = 0;
        return;
    }

    if (s.length() > 0)
    {
        if (s[s.length() - 1] == 'a')
        {
            s.push_back('e');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();
        }
        if (s[s.length() - 1] == 'e')
        {
            s.push_back('a');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();
            s.push_back('i');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();
        }
        if (s[s.length() - 1] == 'i')
        {
            s.push_back('a');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();

            s.push_back('e');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();

            s.push_back('o');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();

            s.push_back('u');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();
        }

        if (s[s.length() - 1] == 'o')
        {
            s.push_back('i');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();

            s.push_back('u');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();
        }
        if (s[s.length() - 1] == 'u')
        {
            s.push_back('a');
            getVowelPermutation(n, s, i + 1, ans);
            s.pop_back();
        }
    }
    else
    {
        s.push_back('a');
        getVowelPermutation(n, s, i + 1, ans);
        s.pop_back();

        s.push_back('e');
        getVowelPermutation(n, s, i + 1, ans);
        s.pop_back();

        s.push_back('i');
        getVowelPermutation(n, s, i + 1, ans);
        s.pop_back();

        s.push_back('o');
        getVowelPermutation(n, s, i + 1, ans);
        s.pop_back();

        s.push_back('u');
        getVowelPermutation(n, s, i + 1, ans);
        s.pop_back();
    }
}

// optimized solution
// basically it is like a tree (choices) and what we need is the width of the tree with height n
int countVowelPermutation(int n)
{
    // find the width of the tree with height n
    long a = 1, e = 1, i = 1, o = 1, u = 1, mod = pow(10, 9) + 7;
    long a2, e2, i2, o2, u2;

    for (int j = 2; j <= n; j++)
    {
        a2 = (e + i + u) % mod;
        e2 = (a + i) % mod;
        i2 = (e + o) % mod;
        o2 = i;
        u2 = (o + i) % mod;

        a = a2, e = e2, i = i2, o = o2, u = u2;
    }
    return (a + e + i + o + u) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "";
    int ans = 0;

    getVowelPermutation(3, "", 0, ans);
    cout << ans << "\n";

    return 0;
}