class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        vector<int> IDXs;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push({s[i],i});
            } else if(s[i] == ')'){
                if(st.empty()){
                    IDXs.push_back(i);
                } else {
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            IDXs.push_back(st.top().second);
            st.pop();
        }
        string res = "";
        for(int i=0; i<s.length(); i++){
            if(find(IDXs.begin(),IDXs.end(),i) == IDXs.end()){
                res.push_back(s[i]);
            }
        }
        
        return res;
        
    }
};