#include <bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &st, int k){
    if(k == 1){
        // when we get the top element we pop it and return so that previously popped ones get restored from the call stack.
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    deleteMiddle(st, k-1);
    // after every return function comes here and then it pops from the call stack and does this operation and we get our stack.
    st.push(temp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<int> st;
    st.push(5);
    st.push(1);    
    st.push(2);    
    st.push(6);    
    st.push(8); 
    st.push(10); 


    deleteMiddle(st, (st.size()/2 + 1));

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}