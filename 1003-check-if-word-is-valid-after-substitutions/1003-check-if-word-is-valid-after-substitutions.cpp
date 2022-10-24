class Solution {
public:
    bool isValid(string s) {
//         stack<char> st;
        
//         st.push(s[0]);
        
//         for(int i=1; i<s.length(); i++){
//             if(st.top() == 'c'){
//                 st.pop();
//             }
//             if(!st.empty()){
//                 char last = st.top();
//                 if(last == 'a'){
//                     if(s[i] == 'b'){
//                         st.pop();
//                     }
//                 } else if(last == 'b'){
//                     if(s[i] == 'c'){
//                         st.pop();
//                     }
//                 } 
//             }
            
            
//             st.push(s[i]);
//         }
        
//         if(st.size() == 1 && st.top() == 'c'){
//             return true;
//         }
        
//         return false;
        
        stack<char>st;
        // set<string>see;
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