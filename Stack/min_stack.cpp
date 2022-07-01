#include <bits/stdc++.h>
using namespace std;

// Using O(N) Space
// For O(1) we can simply use the formula to retain older values.
class MinStack {
public:
    stack<int> st;
    stack<int> sst;

    MinStack() {
        while(!st.empty()){
            st.pop();
        }
        while(!sst.empty()){
            sst.pop();
        }
    }
    
    void push(int val) {
        if(st.size() == 0){
            st.push(val);
            sst.push(val);
            return;
        }
        if(val > sst.top()){
            st.push(val);
            return;
        }
        if(val <= sst.top()){
            st.push(val);
            sst.push(val);
            return;
        }
    }
    void pop() {
        if(st.size() == 0){
            return;
        }
        if(st.top() == sst.top()){
            st.pop();
            sst.pop();
            return;
        }
        else if(st.top() != sst.top()){
            st.pop();
            return;
        }
    }
    
    int top() {
        if(st.size() == 0){
            return -1;
        }
        
        return st.top();
    }
    
    int getMin() {
        if(sst.size() == 0){
            return -1;
        }
        return sst.top();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}