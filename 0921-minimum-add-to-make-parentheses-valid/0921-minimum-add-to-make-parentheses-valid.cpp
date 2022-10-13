class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int closingOnes = 0;
        for(auto it: s){
            if(it == '(') st.push(it);
            else{
                if(st.empty()){
                    closingOnes++;
                }
                else {
                    if(st.top() == '(') st.pop();
                }
            }
        }
        
        return closingOnes + st.size();
    }
};