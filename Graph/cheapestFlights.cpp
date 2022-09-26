#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9+10

class Solution {
public:
    // floyd warshall algo implementation
//     vector<vector<int>> floyd(vector<vector<int>>&flights, int k, int n){
//         vector<vector<int>> dist(n, vector<int>(n, MAX));
        
//         for(int i=0; i<dist.size(); i++){
//             for(int j=0; j<dist[i].size(); j++){
//                 if(i == j) dist[i][j] = 0;
//             }
//         }
        
//         for(auto it: flights){
//             dist[it[0]][it[1]] = it[2];
//         }
        
//         for(int l=0; l <= k; l++){
//             for(int i=0; i<n; i++){
//                 for(int j=0; j<n; j++){
//                     dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
//                 }
//             }
//         }
        
//         return dist;
//     }
    
    // modified djikstra
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>> adj;
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<pair<int,int>, int>> q;
        vector<int> dist(n, INT_MAX);
        q.push({{0,src},0});
        
        while(!q.empty()){
            int cost = q.front().first.first;
            int node = q.front().first.second;
            int counter = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(cost+it.second < dist[it.first] && counter <= k){
                    dist[it.first] = cost+it.second;
                    q.push({{dist[it.first],it.first}, counter+1});
                }
            }
        }
        
        for(auto it: dist){
            if(it == INT_MAX) it = -1;
        }
        
        return dist[dst];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}