class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        map<string, int> mp;
        int res = 0;
        for(auto it: s){
            if(it == 'a') res++;
        }
        
        for(int i=0; i<s.length(); i++){
            st.push(s[i]);
            
            if(s[i] == 'c'){
                char last = st.top();
                st.pop();
                string temp = "";
                temp.push_back(last);
                while(!st.empty() && last-st.top() == 1){
                    last = st.top();
                    temp.push_back(last);
                    st.pop();
                }
                mp[temp]++;
            }
        }
        
        if(mp.size() == 1){
            if(mp.count("cba") != 0){
                if(mp["cba"] == res) return true;
            }
        }
        
        return false;
    }
};