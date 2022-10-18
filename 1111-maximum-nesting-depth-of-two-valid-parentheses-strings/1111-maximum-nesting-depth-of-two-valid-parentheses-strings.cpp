class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> st;
        int maxDepth = INT_MIN;
        vector<int> depths;
        
        for(int i=0; i<seq.length(); i++){
            if(seq[i] == '('){
                st.push(seq[i]);
                depths.push_back((int) st.size());
            } else {
                depths.push_back((int)st.size());
                st.pop();
            }
        }
        
        vector<int> ans;
        for(auto it: depths){
            if(it%2==0)ans.push_back(0);
            else ans.push_back(1);
        }
        
        return ans;
    }
};