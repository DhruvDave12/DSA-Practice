class Solution {
public:
    int minimumDeletions(string s) 
    {
        // no a's before b's
        
        stack<char> st;
        int N = s.length();
        
        int ans = 0;
        for(int i=N-1;i>=0;i--){
            char ch = s[i];
            if(!st.empty() && st.top() < ch){
                ans++;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        
        return ans;
    }
};