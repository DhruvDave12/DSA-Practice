#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int,vector<int>> adj;
    map<int,bool> vis;

    Graph(){
        adj.clear();
        vis.clear();
    }
};


class Solution {
public:

    void helper(map<int,vector<int>> &adj, int sv, int &res, map<int,bool> &vis, int &finalRes){
        vis[sv] = true;
        for(auto it: adj[sv]){
            if(!vis[it]){   
                res++;
                finalRes = max(finalRes, res);
                helper(adj, it, res, vis, finalRes);
                res--;
            }
        } 
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        Graph gh;
        for(int i=0; i<edges.size(); i++){
            gh.adj[edges[i][0]].push_back(edges[i][1]);
            gh.adj[edges[i][1]].push_back(edges[i][0]);
        }

        int res;
        int finalRes;
        vector<pair<int,int>> vec;
        for(auto it: gh.adj){
            finalRes = INT_MIN;   
            res = 0;
            gh.vis.clear();
            helper(gh.adj,it.first,res,gh.vis,finalRes);
            // cout<<it.first<<" -> "<<finalRes<<"\n";
            vec.push_back({finalRes, it.first});
        }
        sort(vec.begin(), vec.end());
        int val = vec[0].first;
        for(auto it: vec){
            if(it.first == val){
                res.push_back(it.second);
            }
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> edges = {{3,0}, {3,1}, {3,2}, {3,4}, {5,4}};
    int n = 6;

    Solution s;
    s.findMinHeightTrees(n,edges);
    return 0;
}