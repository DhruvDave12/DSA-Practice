#include <bits/stdc++.h>
using namespace std;

void insertStack(stack<int> &st, int temp){
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }

    int x = st.top();
    st.pop();
    insertStack(st, temp);
    st.push(x);
    return;
}

void sortStack(stack<int> &st){
    if(st.size() <= 1){
        return;
    }

    int temp = st.top();
    st.pop();
    sortStack(st);
    insertStack(st, temp);
    // insert temp on its correct position
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

    sortStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}