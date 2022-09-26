#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        

        res[0].push_back(1);
        
        for(int i=1; i<numRows; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i) {
                    res[i].push_back(1);
                }
                else {
                    res[i].push_back(res[i-1][j] + res[i-1][j-1]);
                }
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