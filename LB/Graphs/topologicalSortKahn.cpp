#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    map<int, vector<int>> adj;

    void addEdgeDirected(int u, int v){
        adj[u].push_back(v);
    }
};

vector<int> topologicalSortKahn(map<int, vector<int>> &adj, int N){
    vector<int> indegrees(N, 0);
    for(int i=0; i<N; i++){
        for(auto it: adj[i]){
            indegrees[it]++;
        }
    }

    // now we have the indegrees now simply just iterate in BFS manner
    queue<int> q;
    vector<int> ans;
    // assuming we have elements as 0 1 2 3 4 ....
    for(int i=0; i<indegrees.size(); i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int temp = q.front();
        ans.push_back(temp);
        q.pop();
        for(auto it: adj[temp]){
            indegrees[it]--;
            if(indegrees[it] == 0){
                q.push(it);
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph gh;
    gh.addEdgeDirected(5,0);
    gh.addEdgeDirected(4,0);
    gh.addEdgeDirected(5,2);
    gh.addEdgeDirected(4,1);
    gh.addEdgeDirected(2,3);
    gh.addEdgeDirected(3,1);

    vector<int> ans = topologicalSortKahn(gh.adj, 5);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}