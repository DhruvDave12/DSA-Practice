class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto it: s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            } else {
                if(st.empty()) return false;
                int x = abs(st.top()-it);
                if(x!=1 && x!=2) return false;
                st.pop();
            }
        }
        
        return st.empty();
    }
};