class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                if(st.size() >= 1){
                    ans.push_back('(');
                }
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(st.size() > 1){
                    // means we have a primitive one inside;
                    ans.push_back(')');
                }
                st.pop();
            }
        }
        
        return ans;
    }
};