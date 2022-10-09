class Solution {
public:
     
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // we will have to use the modified djikstra
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        vector<int> dR = {0,1,0,-1};
        vector<int> dC = {1,0,-1,0};
        
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int> (m, INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty()){
            int dista = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i=0; i<4; i++){
                int nR = r+dR[i];
                int nC = c+dC[i];
                
                if(nR >= 0 && nR < n && nC >= 0 && nC < m){
                    int newEff = max(dista,abs(heights[r][c] - heights[nR][nC]));
                    if(newEff < dist[nR][nC]){
                        dist[nR][nC] = newEff;
                        pq.push({newEff,{nR,nC}});
                    }
                    
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};