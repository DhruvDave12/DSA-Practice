#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph. (Starts from 0 given)
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        // Code here
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        // vector<int> :: iterator it;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto it: adj[x]){
                if(!visited[it]){
                    q.push(it);
                }
                visited[it] = true;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}