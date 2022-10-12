class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
                continue;
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