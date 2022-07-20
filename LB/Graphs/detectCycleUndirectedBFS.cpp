#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
    bool isCyclicUtil(int sv, int V, map<int,vector<int>> &adj, map<int,bool> &visited){
        queue<pair<int,int>> q;
        q.push({sv, -1});

        while(!q.empty()){
            pair<int,int> pp = q.front();
            q.pop();
            int curr = pp.first;
            int par = pp.second;

            for(auto it: adj[curr]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it,curr});
                }

                if(it != par) return true;
            }
        }

        return false;
    }

    bool isCyclic(map<int,vector<int>> &adj, int sv, int V){
        map<int, bool> visited;

        for(int i=0;i<V; i++){
            if(!visited[i]){
                if(isCyclicUtil(i,V,adj,visited)) return true;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}