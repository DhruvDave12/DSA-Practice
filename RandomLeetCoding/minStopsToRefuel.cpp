#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel >= target) return 0;
        int dis = startFuel, stops = 0;
        priority_queue<pair<int,int>> pq;
        
        int i = 0, prevStop = 0;

        while(dis < target){
            // searching for the station with max fuel
            while(i<stations.size() && dis >= (stations[i][0]-prevStop)){
                pq.push({stations[i][1], stations[i][0]});
                i++;
            }
            // if we cannot reach any station we return -1
            if(pq.empty()) return -1;

            // extracting the station with max fuel and its dist 
            int maxFuel = pq.top().first;
            int maxPos = pq.top().second;
            pq.pop();

            // updating the dis with the remaining fuel + refilled fuel
            dis = dis-(maxPos-prevStop) + maxFuel;

            // updating the target showing how close we are to the target now
            target = target-(maxPos-prevStop);

            // updating the prevStop
            prevStop = maxPos;

            // updating stops
            stops++;
        }
        return stops;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}