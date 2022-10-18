class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        
        vector<int> res(temperatures.size(), 0);
        st.push({temperatures[temperatures.size()-1], temperatures.size()-1});
        for(int i=temperatures.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }          
            if(!st.empty()){
                res[i] = st.top().second-i;
            }
            
            st.push({temperatures[i],i});
        }
        
        return res;
    }
};