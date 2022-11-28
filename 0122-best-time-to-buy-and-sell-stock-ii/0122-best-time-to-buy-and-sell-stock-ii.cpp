class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curr = prices[0];
        // int limit = 2;
        
        for(int i=1;i<prices.size(); i++){
            // if(limit == 0) break;
            if(prices[i] <= curr){
                cout<<curr<<"\n";
                curr = prices[i];
            }    
            
            else if(prices[i] > curr){
                int sellDay = INT_MIN;
                while(i<prices.size() && prices[i] >= sellDay){
                    sellDay = max(sellDay, prices[i]);
                    i++;
                }
                int x = 0;
                if(i < prices.size()){
                    x = prices[i];
                }
                // cout<<sellDay<<" "<<curr<<"\n";
                profit += sellDay-curr;
                curr = x;
                // limit--;
                i--;
            }
        }
        
        return profit;
    }
};