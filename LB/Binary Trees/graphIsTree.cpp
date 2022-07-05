#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int,bool> vis;
    map<int, vector<int>> adj;

    // undirected
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u){
        vis[u] = true;
        cout<<u<<" ";
        
        vector<int> :: iterator itr;
        for(itr = adj[u].begin(); itr != adj[u].end(); itr++){
            if(!vis[*itr]){
                dfs(*itr);
            }
        }
    }
};

// if the graph has a cycle then it is not a tree else it is a tree

bool isCyclicUtil(int v, map<int,bool> &visited, int parent, map<int, vector<int>> &adj){
    visited[v] = true;

    vector<int> :: iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); itr++){
        // now we are here traversing on the child of v so parent is v
        if(!visited[*itr]){
            if(isCyclicUtil(*itr, visited, v, adj)){
                return true; 
            }
        }
        // else if the node is already visited means that it must be parent for the current element
        // so if it is not parent of current set means there is a cycle
        else if(*itr != parent){
            return true;
        }
    }
    return false;
    
}

bool isTree(map<int, vector<int>> &adj, map<int,bool> visited){
    map<int,bool> :: iterator it;
    for(it=visited.begin(); it!=visited.end(); it++){
        it->second = false;
    }

    if(isCyclicUtil(0,visited, -1, adj)){
        return false;
    }

    // if any node missed by the isCyclicUtil so we return false
    for(it = visited.begin(); it != visited.end(); it++){
        if(it->second == false){
            return false;
        }
    }

    // if all visited and no cycles found so we get true
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gp;

    int n,e;
    cin>>n>>e;

    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        gp.addEdge(u,v);
    }

    // int startVertex;
    // cin>>startVertex;

    // gp.dfs(startVertex);
    
    if(isTree(gp.adj, gp.vis)){
        cout<<"Graph is a tree"<<"\n";
    } else {
        cout<<"Graph is not a tree"<<"\n";
    }
    return 0;
}