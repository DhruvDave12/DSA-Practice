class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> brickPQ;
        
        bool flag = false;
        int i=0;
        for(i=1; i<heights.size(); i++){
            if(heights[i]-heights[i-1] <= 0) continue;
            int heightNeeded = heights[i]-heights[i-1];
            if(bricks >= heightNeeded){
                bricks -= heightNeeded;
                brickPQ.push(heightNeeded);
            }
            
            else if(ladders > 0) {
                if(!brickPQ.empty()){
                    int maxUsedBefore = brickPQ.top();
                    if(maxUsedBefore >= heightNeeded){
                        ladders--;
                        brickPQ.pop();

                        int rem = maxUsedBefore - heightNeeded;
                        brickPQ.push(heightNeeded);
                        bricks += rem;
                    } else {
                        ladders --;
                    }  
                } else {
                    ladders --;
                }
            } else {
                flag = true;
                break;
            }
        }
        
        if(flag){
            cout<<i<<"\n";
            return i-1;
        }
        
        return heights.size()-1;
        
    }
};