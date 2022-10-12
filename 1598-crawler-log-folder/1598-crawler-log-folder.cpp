class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        
        for(auto it: logs){
            if(it[0] != '.'){
                st.push(it);
            }
            else if(it[0] == '.' && it[1] == '.'){
                if(st.empty()) continue;
                st.pop();
            }
        }
        
        return st.size();
    }
};