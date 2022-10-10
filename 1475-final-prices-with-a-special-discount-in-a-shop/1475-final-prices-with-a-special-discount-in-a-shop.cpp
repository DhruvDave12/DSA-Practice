class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(prices[prices.size()-1]);
        
        for(int i=prices.size()-2; i>=0; i--){
            while(!st.empty() && prices[i] < st.top()){
                st.pop();
            }
            if(!st.empty()){
                int temp = st.top();
                st.push(prices[i]);
                prices[i] -= temp;
            } else {
                st.push(prices[i]);
            }
            
        }
        
        return prices;
    }
};