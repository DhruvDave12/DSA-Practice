class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            if(!st.empty()){
                if(abs(st.top()-s[i]) == 32){
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};