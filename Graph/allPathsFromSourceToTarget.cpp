#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<int>> &graph, vector<int> &temp, vector<vector<int>> &ans, int curr, map<int,bool> &xyz){
        xyz[curr] = true;
        temp.push_back(curr);
        for(auto it: graph[curr]){
            if(!xyz[it]){
                dfs(graph,temp,ans,it,xyz);
                temp.pop_back();
            }
        }

        ans.push_back(temp);
    }   

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        vector<vector<int>> res;
        map<int,bool> vis;
        dfs(graph,temp,res,0,vis);

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}