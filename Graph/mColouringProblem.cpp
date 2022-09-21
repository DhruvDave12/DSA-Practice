#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int,vector<int>> adj;
    map<int,bool> vis;
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

class Solution{
public:

    pair<int,bool> canColor(int m, map<int,int> &color, vector<int> &adjNodes){
        bool flag = false;
        for(int i=1; i<=m; i++){
            flag = false;
            for(int j=0; j<adjNodes.size(); j++){
                if(color.count(adjNodes[j]) != 0 && color[adjNodes[j]] == i){
                    flag = true;
                    break;
                }
            }
            if(!flag) return make_pair(i,true);
        }
        return make_pair(-1,false);
    }

    bool dfs(Graph gh, int sv, map<int,int>&color, int m){
        gh.vis[sv] = true;
        
        pair<int,bool> possibility = canColor(m,color,gh.adj[sv]);
        if(!possibility.second) return false;
        color[sv] = possibility.first;

        for(auto it: gh.adj[sv]){
            // here we have the neighbouring elements
            if(!gh.vis[sv]){
                if(!dfs(gh,it,color,m)) return false;
            }
        }

        return true;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        Graph gh;
        // your code here
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                if(graph[i][j]){
                    gh.addEdge(i,j);
                }
            }
        }

        // now we have the graph in form of adjacency list
        map<int,int> colorMapper;
        bool res = dfs(gh,0,colorMapper,m);
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}