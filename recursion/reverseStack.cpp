#include <bits/stdc++.h>
using namespace std;

// Every item of recursion goes in a call stack and then when we return it gets popped back into main stack
void reverseStack(stack<int> &st){
    if(st.size() <= 1){
        return;
    }

    int temp = st.top();
    st.pop();
    reverseStack(st);
    st.push(temp);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}