#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int,vector<int>> adj;
    Graph(){
        adj.clear();
    }
};

class Solution {
public:
    void fillStack(map<int,vector<int>> &adj, stack<int>&st, vector<bool>&vis, int curr){
        vis[curr] = true;

        for(auto it: adj[curr]){
            if(!vis[it]) fillStack(adj, st, vis, it);
        }

        st.push(curr);
    }

    void fillVectorKahn(map<int,vector<int>> &adj, int N, vector<int> &vec){
        vector<int> indegrees(N, 0);
        for(int i=0; i<N; i++){
            for(auto it: adj[i]){
                indegrees[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<N; i++){
            if(indegrees[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int temp = q.front();
            vec.push_back(temp);
            q.pop();
            for(auto it: adj[temp]){
                indegrees[it]--;
                if(indegrees[it] == 0){
                    q.push(it);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph gh;
        for(int i=0; i<prerequisites.size(); i++){
            gh.adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // vector<bool> vis(2001, false);
        vector<int> res;
        // stack<int> st;
        // for(int i=0; i<vis.size(); i++){    
            
        //     if(!vis[i]){
        //         fillStack(gh.adj, st, vis, i);
        //         while(!st.empty()){
        //             res.push_back(st.top());
        //             st.pop();
        //         }
        //     }
        // }

        fillVectorKahn(gh.adj, numCourses, res);
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}