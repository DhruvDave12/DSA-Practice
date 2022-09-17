#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int,vector<int>> graph;

    bool hasCycle(vector<bool> &vis, vector<bool> &recVis, int curr){
        vis[curr] = true;
        recVis[curr] = true;

        for(auto it: graph[curr]){
            if(!vis[it]){
                hasCycle(vis,recVis,it);
            }
            if(recVis[it]) return true;
        }

        recVis[curr] = false;
        return false;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // check if the graph has cycle or not
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }

        // now the graph is ready we just have to check if this directed graph has any cycle or not
        vector<bool> vis(N, false);
        vector<bool> recVis(N, false);

        for(int i=0; i<N; i++){
            if(!vis[i]){
                if(hasCycle(vis,recVis,i)) return false;
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