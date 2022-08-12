#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int getCeleb(vector<vector<int> >& M, int n){
        int count;
        for(int i=0; i<M.size(); i++){
            count = 0;
            for(int j=0; j<M[i].size(); j++){
                if(M[i][j] == 0) count++;
            }
            if(count == M[i].size()) return i;
        } 

        return -1;
    }

    int celebrity(vector<vector<int> >& M, int n) 
    {
        // check 1 -> there must exist a person that doesnt know anyone
        // check2 -> there must be a person that is known by all others
        int celebIdx = getCeleb(M,n);
        int count = 0;

        if(celebIdx == -1) return -1;

        for(int i=0; i<M.size(); i++){
            if(i == celebIdx) continue;
            if(M[i][celebIdx] == 1) count++;
        }

        if(count == n-1) return celebIdx;

        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}