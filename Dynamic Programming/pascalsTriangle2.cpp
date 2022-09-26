#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void preCompute(vector<vector<int>> &res){
        res[0].push_back(1);
        for(int i=1;i<34; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    res[i].push_back(1);
                }
                else {
                    res[i].push_back(res[i-1][j] + res[i-1][j-1]);
                }
            }
        }
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res(34);
        preCompute(res);
        
        return res[rowIndex];
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}