#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<bool> vis(V,false);
        vector<int> key(V,INT_MAX);
        vector<int> parent(V,INT_MAX);

        key[0] = 0;
        parent[0] = -1;

        for(int i=0; i<V; i++){
            // get the minimum of the key arr
            int mini = INT_MAX, u = 0;
            for(int i=0; i<key.size(); i++){
                if(mini < key[i] && !vis[i]){
                    mini = key[i];
                    u = i;
                }
            }

            vis[u] = true;
            // now we will traverse in and update the key arr
            // for(int i=0; i<adj->size(); i++){
            //     if(adj[i][0] == u){
            //         int toVisit = adj[i][1];
            //         int weight = adj[i][2];

                            // now just update on the condition of getting the min weight for each one
                            
            //     }
            // }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}