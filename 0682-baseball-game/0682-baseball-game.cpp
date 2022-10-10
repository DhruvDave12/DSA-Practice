class Solution {
public:
    
    bool isOp(string x){
        if(x == "+" || x == "D" || x == "C") return true;
        return false;
    }
    
    
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for(int i=0; i<operations.size(); i++){
            if(!isOp(operations[i])){
                int dec = stoi(operations[i]);
                st.push(dec);
            } else {
                if(operations[i] == "+"){
                    int f = st.top();
                    st.pop();
                    if(!st.empty()){
                        int s = st.top();
                        st.pop();
                        st.push(s);
                        st.push(f);
                        st.push(f+s);    
                    }
                } else if (operations[i] == "D"){
                    int f = st.top();
                    st.push(2*f);
                } else if (operations[i] == "C"){
                    st.pop();
                }
            }
        }
        
        
        int ans = 0;
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};