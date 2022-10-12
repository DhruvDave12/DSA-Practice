class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> st2;
        
        for(auto it: s){
            if(it == '#' && !st.empty()){
                st.pop();
            } else if(st.empty() && it == '#') {
                continue;
            }
            else{
                st.push(it);
            }
        }
        
        for(auto it: t){
            if(it == '#' && !st2.empty()){
                st2.pop();
            } else if(st2.empty() && it == '#') {
                continue;
            }
            else{
                st2.push(it);
            }
        }
        
        if(st.size() != st2.size()) return false;
        
        while(!st.empty()){
            if(st.top() != st2.top()) return false;
            st.pop();
            st2.pop();
        }
        
        return true;
    }
};