class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stQ;
        stack<int> st;
        
        for(auto it: students) stQ.push(it);
        for(int i=sandwiches.size()-1; i>=0; i--) st.push(sandwiches[i]);
        
        
        queue<int> q;
        while(!st.empty()){
            int sand = st.top();
            if(stQ.front() == sand){
                st.pop();
                stQ.pop();
            } else {
                while(!stQ.empty() && stQ.front() != sand){
                    q.push(stQ.front());
                    stQ.pop();
                }
                if(stQ.empty()){
                    return q.size();
                }
                while(!q.empty()){
                    stQ.push(q.front());
                    q.pop();
                }
            }
        }
        return stQ.size();
    }
};