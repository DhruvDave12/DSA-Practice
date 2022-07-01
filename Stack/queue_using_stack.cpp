#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        while(!st1.empty()){
            st1.pop();
        }
        while(!st2.empty()){
            st2.pop();
        }
    }
    
    void push(int x) {
        if(st1.empty()){
            st1.push(x);
            return;
        }
        while(!st1.empty()){
            int z = st1.top();
            st1.pop();
            st2.push(z);
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if(st1.empty()){
            return -1;
        }
        int ans = st1.top();
        st1.pop();
        return ans;
    }
    
    int peek() {
        if(st1.empty()){
            return -1;
        }
        int ans = st1.top();
        return ans;
    }
    
    bool empty() {
        if(st1.empty()){
            return true;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}