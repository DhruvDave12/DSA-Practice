#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isCyclic(map<int, vector<int>>&adj, vector<bool> &vis, int sv, vector<bool>&recVis){
        vis[sv] = true;
        recVis[sv] = true;

        for(auto it: adj[sv]){
            if(!vis[it]){
                if(isCyclic(adj, vis, it, recVis)){
                    return true;
                }
            }
            if(recVis[it] && it != sv) return false;
        }

        recVis[sv] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> adj;
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> vis(2001, false);
        vector<bool> recVis(2001, false);
        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                if(isCyclic(adj, vis, i, recVis)){
                    return false;
                }
            }
        }

        return true;
    } 
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}