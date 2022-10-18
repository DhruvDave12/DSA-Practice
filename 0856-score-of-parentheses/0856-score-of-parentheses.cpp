class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int ans = 0;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            } else {
                int x = st.size();
                while(i < s.length() && s[i] == ')'){
                    st.pop();
                    i++;
                }
                ans += pow(2,x-1);
                i--;
            }
        }
        
        return ans;
    }
};