#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    bool reachable(int i, int j, int row, int col){
        if(i < 0 || j < 0) return false;
        if(i >= row || j >= col) return false;
        return true;
    }
    void fillVector(vector<vector<int>> &m, int i, int j, vector<string> &res, string output, vector<vector<bool>> &vis){
        int row = m.size();
        int col = m[0].size();
        if(!reachable(i,j,row,col)) return;

        if(vis[i][j]) return;
        vis[i][j] = true;

        if(i == row-1 && j == col-1) {
            res.push_back(output);
        }

        if(reachable(i+1,j,row,col) && m[i+1][j] == 1){
            output.push_back('D');
            fillVector(m,i+1,j,res,output,vis);
            if(output.size() > 0) output.pop_back();
        }
        if(reachable(i,j+1,row,col) && m[i][j+1] == 1){
            output.push_back('R');
            fillVector(m,i,j+1,res,output,vis);
            if(output.size() > 0) output.pop_back();

        }
        
        if(reachable(i-1,j,row,col) && m[i-1][j] == 1){
            output.push_back('U');
            fillVector(m,i-1,j,res,output,vis);
            if(output.size() > 0) output.pop_back();
        }
        if(reachable(i,j-1,row,col) && m[i][j-1] == 1){
            output.push_back('L');
            fillVector(m,i,j-1,res,output,vis);
            if(output.size() > 0) output.pop_back();
        }
        // vimp to remove that from the rec stack and we could visit again
        vis[i][j] = false;

        // return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Here we are going to do a simple dfs traversal and check all paths and then put the string in vector
        vector<string> res;
        string output = "";
        int i = 0;
        int j = 0;
        if(m[m.size()-1][m[0].size()-1] == 0) return {};
        vector<vector<bool>> vis(m.size(), vector<bool>(m[0].size(), false));
        fillVector(m,i,j,res,output,vis);

        return res;
    }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    

    vector<vector<int>> vec = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    int n = 4;

    vector<string> res = Solution().findPath(vec, n);

    for(int i=0;i<res.size(); i++){
        cout<<res[i]<<"\n";
    }
    // string s = "";
   
    return 0;
}