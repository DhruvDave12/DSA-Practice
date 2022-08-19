#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, vector<int>> adj;
    bool helper(vector<bool> &vis, vector<bool> &recVis, int v){
        vis[v] = true;
        recVis[v] = true;

        for(auto it: adj[v]){
            if(!vis[it]){
                if(helper(vis, recVis, it)) return true;
            }
            if(recVis[it]) return true;
        }
        recVis[v] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, int> mp;
        for(int i=0; i<prerequisites.size(); i++){
            mp[prerequisites[i][0]] = prerequisites[i][1];
        }

        for(int i=0; i<prerequisites.size(); i++){
            
        }

    } 
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}