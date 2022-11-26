class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        for(auto it: s){
            if(it != ' '){
                temp.push_back(it);
            } else {
                st.push(temp);
                temp = "";
            }
        }

        st.push(temp);

        string ans = "";
        while(!st.empty()){
            if(st.top() != ""){
                ans += st.top();
                ans.push_back(' ');
            }
            st.pop();
        }

        ans.pop_back();

        return ans;
    }
};