#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:

    map<int,vector<int>> adj;

    void addEdgeDirected(int u, int v){
        adj[u].push_back(v);
    }
};

class StronglyConnectedComponents {
    public:

    void dfsOnComponent(map<int,vector<int>> &adj, int sv, vector<bool> &vis, vector<int> &vec){
        vis[sv] = true;
        vec.push_back(sv);
        for(auto it: adj[sv]){
            if(!vis[it]){
                dfsOnComponent(adj,it,vis,vec);
            }
        }
    }
    vector<vector<int>> getStronglyConnectedComponents (map<int,vector<int>> &adj, int N) {
        vector<bool> vis(N, false);
        vector<int> temp;
        vector<vector<int>> vec;
        
        for(int i=N;i>0;i--){
            if(!vis[i]){
                temp.clear();
                dfsOnComponent(adj,i,vis,temp);
                if(find(vec.begin(), vec.end(), temp) == vec.end()){
                    vec.push_back(temp);
                }
            }
        }

        return vec;
    }

};

class KosaRaju {
    public:
    
    void getTopo(map<int,vector<int>>&adj, int sv, vector<bool> &vis, stack<int> &st){
        vis[sv] = true;
        for(auto it: adj[sv]){
            if(!vis[it]){
                getTopo(adj, it, vis, st);
            }
        }
        st.push(sv);
    }

    void reverseDFS(map<int,vector<int>> &adjRev, vector<bool> &vis, int sv){
        vis[sv] = true;
        cout<<sv<<" ";
        for(auto it: adjRev[sv]){
            if(!vis[it]){
                reverseDFS(adjRev, vis, it);
            }
        }
    }

    void doKosaRaju(map<int,vector<int>>&adj, int N){
        stack<int> st;
        vector<bool> vis(N+1, false);
        for(int i=1; i<=N; i++){
            if(!vis[i]){
                getTopo(adj, i, vis, st);
            }
        }
        // now we have the nodes sorted in order of increasing finish time
        // now we will get the transpose of the map
        map<int,vector<int>> transpose;
        map<int,vector<int>> :: iterator itr;
        for(itr = adj.begin(); itr != adj.end(); itr++){
            vis[itr->first] = false;
            for(int i=0;i<itr->second.size(); i++){
                transpose[itr->second[i]].push_back(itr->first);
            }
        }
        // vector<bool> vis2(N+1,false);
        while(!st.empty()){
            int x = st.top();
            if(!vis[x]){
                reverseDFS(transpose, vis, x);
                cout<<endl;
            }
            st.pop();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;
    gh.addEdgeDirected(1, 2);
    gh.addEdgeDirected(2, 3);
    gh.addEdgeDirected(3, 1);
    gh.addEdgeDirected(2, 4);
    gh.addEdgeDirected(4, 5);
    int N1 = 5;

    Graph gh2;
    gh2.addEdgeDirected(2,1);
    gh2.addEdgeDirected(1,3);
    gh2.addEdgeDirected(3,2);
    gh2.addEdgeDirected(3,5);
    gh2.addEdgeDirected(5,4);
    gh2.addEdgeDirected(4,6);
    gh2.addEdgeDirected(6,5);
    int N2 = 6;

    StronglyConnectedComponents s;
    vector<vector<int>> ans1 = s.getStronglyConnectedComponents(gh.adj, N1);

    vector<vector<int>> ans2 = s.getStronglyConnectedComponents(gh2.adj, N2);

    cout<<"FIRST\n";
    for(int i=0; i<ans1.size(); i++){
        for(int j=0; j<ans1[i].size(); j++){
            cout<<ans1[i][j]<<" ";
        }cout<<endl;
    }

    cout<<"\nSECOND\n";
    for(int i=0; i<ans2.size(); i++){
        for(int j=0; j<ans2[i].size(); j++){
            cout<<ans2[i][j]<<" ";
        }cout<<endl;
    }

    cout<<"KOSA RAJU OUTPUTS: "<<"\n";
    KosaRaju k;
    k.doKosaRaju(gh.adj, N1);
    cout<<endl; 
    k.doKosaRaju(gh2.adj, N2);
    return 0;
}