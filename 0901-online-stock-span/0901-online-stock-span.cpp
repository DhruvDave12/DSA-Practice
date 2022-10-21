class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        st = stack<pair<int,int>>();    
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        }
        if(st.top().first > price) {
            st.push({price,1});
            return 1;
        }
        
        int ans = 1;
        while(!st.empty() && st.top().first <= price){
            ans += st.top().second;
            st.pop();
        }
        
        st.push({price,ans});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */