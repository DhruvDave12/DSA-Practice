class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int i = 0, j = 0;
        while(i < pushed.size() && j < popped.size()){
            if(popped[j] != pushed[i]){
                st.push(pushed[i]);
            } else {
                st.push(pushed[i]);
                while(!st.empty() && st.top() == popped[j]){
                    j++;
                    st.pop();
                }
            }
            i++;
        }
        
        if(st.size() == 0) return true;
        return false;
    }
};