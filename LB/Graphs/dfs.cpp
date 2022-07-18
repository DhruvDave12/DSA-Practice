#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void fillVector(vector<int> adj[], int vertex, vector<int> &ans, vector<bool> &visited){
        visited[vertex] = true;
        ans.push_back(vertex);
        for(auto i : adj[vertex]){
            if(!visited[i]){
                fillVector(adj, i, ans, visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> ans;
        
        fillVector(adj, 0, ans, visited);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}