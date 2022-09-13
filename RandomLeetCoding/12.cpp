#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        if (power < tokens[0])
            return 0;
        int score = 0;

        power -= tokens[0];
        score++;
        int itr = 1;
        int lastOnes = tokens.size()-1;
        // now we are in the array now check if u could take

        int res = INT_MIN;
        while(itr != lastOnes){
            res = max(res, score);
            if(tokens[itr] <= power){
                power -= tokens[itr];
                score++;
                itr++;
            }
            else {
                score--;
                power += tokens[lastOnes];
                lastOnes--;
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