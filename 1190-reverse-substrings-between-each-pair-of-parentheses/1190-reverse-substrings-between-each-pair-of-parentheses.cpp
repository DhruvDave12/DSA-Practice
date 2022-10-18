class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        queue<char> temp;
        for(auto it: s){
            if(it != ')'){
                st.push(it);
            }
            else{
                temp = queue<char>();
                while(!st.empty() && st.top() != '('){
                    temp.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!temp.empty()){
                    st.push(temp.front());
                    temp.pop();
                }
            }
        }
        
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};