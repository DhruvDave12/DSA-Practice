#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int, vector<int>> adjList;
    map<int, bool> visited;
    int edges;
    int vertices;

    Graph(){
        adjList.clear();
        visited.clear();
    }

    void addEdgeUndirected(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void addEdgeDirected(int u, int v){
        adjList[u].push_back(v);
    }
};

// TC -> O(V+E)
void dfs(map<int,vector<int>> &adj, map<int,bool> &vis, int startFrom){
        vis[startFrom] = true;
        cout<<startFrom<<" ";
        vector<int> :: iterator itr;
        for(itr = adj[startFrom].begin(); itr != adj[startFrom].end(); itr++){
            if(!vis[*itr]){
                dfs(adj,vis,*itr);
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // We are using undirected graph right now if directed then we have the routine for that too in the class made
    int e,v;
    cin>>e>>v;

    Graph gh;
    for(int i=0; i<e; i++){
        int start,end;
        cin>>start>>end;

        gh.addEdgeUndirected(start, end);
    }

    int s;
    cin>>s;
    dfs(gh.adjList, gh.visited, s);
    return 0;
}