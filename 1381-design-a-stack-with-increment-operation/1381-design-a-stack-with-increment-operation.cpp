class CustomStack {
public:
    stack<int> st;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size() >= maxSize) return;
        st.push(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int x = st.top();
        st.pop();
        return x;
    }
    
    void increment(int k, int val) {
        
        stack<int> temp;
        int currSize = st.size();
        if(k >= currSize){
            while(!st.empty()){
                int newVal = st.top() + val;
                temp.push(newVal);
                st.pop();
            }
            
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
        else {
            int i = 0;
            while(i != currSize-k && !st.empty()){
                temp.push(st.top());
                st.pop();
                i++;
            }
            
            while(!st.empty()){
                int newVal = st.top() + val;
                temp.push(newVal);
                st.pop();
            }
            
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */