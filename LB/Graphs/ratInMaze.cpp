#include <bits/stdc++.h>
using namespace std;

class Solution{
      public:
    void fillVector(vector<vector<int>> &m, int i, int j, int n, vector<string> &sVec, string s){
        if(i>=n or j>=n or i<0 or j<0 or m[i][j] == 0) return;
        if(i==n-1 and j==n-1) {
            sVec.push_back(s);
            return;
        }
        m[i][j] = 0;
        fillVector(m,i-1,j,n,sVec,s+"U");
        fillVector(m,i,j+1,n,sVec,s+"R");
        fillVector(m,i,j-1,n,sVec,s+"L");
        fillVector(m,i+1,j,n,sVec,s+"D");
        m[i][j] = 1;
        return;

    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> sVec;
        string s = "";
        int i=0, j=0;
        fillVector(m,0,0,n,sVec,"");
        return sVec;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> m = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 } };
    int n = 5;

    Solution s;
    vector<string> st = s.findPath(m,n);
    for(int i=0; i<st.size();i++){
        cout<<st[i]<<"\n";
    }
    return 0;
}