#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<bool> populatePrimesSieve(int right)
    {
        vector<bool> prime(right, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i * i <= right; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= right; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

public:
    int countPrimeSetBits(int left, int right)
    {
        int counter = 0;
        vector<bool> primeNums = populatePrimesSieve(32);
        for (int i = left; i <= right; i++)
        {
            int setBits = __builtin_popcount(i);
            // cout<<setBits<<"\n";
            if (primeNums[setBits])
            {
                counter++;
            }
        }

        return counter;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int setBits = __builtin_popcount(5);

    Solution s;
    s.countPrimeSetBits(6, 10);
    return 0;
}