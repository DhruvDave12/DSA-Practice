#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    // 7 1 5 3 6 4
        stack<int> st;
        st.push(prices[prices.size()-1]);
        int ans = 0;
        for(int i=prices.size()-2; i>=0; i--){
            if(prices[i] > st.top()){
                st.push(prices[i]);
            }
            else if(prices[i] < st.top()){
                ans = min(ans, st.top()-prices[i]);
                if(ans < 0){
                    ans = 0;
                }
            }
        }

        return ans;
    }

    int moreEfficientOptimisation(vector<int> &prices){
        int left = 0;
        int maxx = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[left] <= prices[i]){
                int profit = prices[i] - prices[left];
                maxx = max(maxx, profit);
            }
            else{
                left = i;
            }
        }

        return maxx;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}