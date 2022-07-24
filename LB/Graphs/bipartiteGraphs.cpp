#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int, vector<int>> adj;
    map<int, bool> vis;

    Graph(){
        adj.clear();
        vis.clear();
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  
};

class Sol {
    public:
    bool isBipartiteBFS(map<int,vector<int>> &adj, int sv){

        vector<bool> visited(adj.size(), false);
        vector<int> color(adj.size(), -1);
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        color[sv] = 0;
        vector<int> :: iterator itr;

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(itr = adj[temp].begin(); itr != adj[temp].end(); itr++){
                if(!visited[*itr]){
                    q.push(*itr);
                    visited[*itr] = true;
                    if(color[temp] == 1){
                        color[*itr] = 0;
                    }
                    else if(color[temp] == 0){
                        color[*itr] = 1;
                    }
                }

                else if(color[*itr] == color[temp]){
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartiteDFSUtil(map<int,vector<int>> &adj, int sv, vector<int> &color, vector<bool> &visited, int par){
        visited[sv] = true;
        if(par != -1 && color[par] == 1){
            color[sv] = 0;
        }
        else if(par != -1 && color[par] == 0){
            color[sv] = 1;
        }

        for(auto it: adj[sv]){
            if(!visited[it]){
                isBipartiteDFSUtil(adj,it,color,visited,sv);
            }
            else if(color[sv] == color[it]){
                return false;
            }
        }

        return true;
    }

    bool isBipartiteDFS(map<int, vector<int>> &adj, int sv){
        vector<bool> visited(adj.size(), false);
        vector<int> color(adj.size(), -1);
        color[sv] = 0;
        bool ans = isBipartiteDFSUtil(adj,sv,color,visited,-1);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;

    gh.addEdge(1,2);
    gh.addEdge(2,3);
    // gh.addEdge(1,3);
    
    Sol s;
    // if(s.isBipartiteBFS(gh.adj, 1)){
    //     cout<<"GRAPH IS BIPARTITE BFS"<<"\n";
    // } else {
    //     cout<<"GRAPH IS NOT BIPARTITE BFS"<<"\n";
    // }

    if(s.isBipartiteDFS(gh.adj, 1)){
        cout<<"GRAPH IS BIPARTITE DFS"<<"\n";
    } else {
        cout<<"GRAPH IS NOT BIPARTITE DFS"<<"\n";
    }

    return 0;
}