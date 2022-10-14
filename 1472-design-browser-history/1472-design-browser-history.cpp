class BrowserHistory {
public:
    stack<string> st;
    stack<string> temp;
    
    BrowserHistory(string homepage) {
        st.push(homepage);    
        temp = stack<string>();
    }
    
    void visit(string url) {
        st.push(url);
        temp = stack<string>();
    }
    
    string back(int steps) {
        int i = 0;
        while(i != steps && st.size() > 1){
            temp.push(st.top());
            st.pop();
            i++;
        }
        
        string res = !st.empty() ? st.top() : "";
        return res;
    }
    
    string forward(int steps) {
        int i = 0;
        while(i != steps && !temp.empty()){
            st.push(temp.top());
            temp.pop();
            i++;
        }
        
        string res = !st.empty() ? st.top() : "";
        return res;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */