#include <bits/stdc++.h>
using namespace std;

void test(stack<int> &st, int x){
    if(st.empty()) {
        st.push(x);
        return;
    }
    else if(st.top() >= x){
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    test(st,x);
    st.push(y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<int> st;
    test(st,5);
    test(st,1);
    test(st,0);
    test(st,1);
    test(st,-3);
    test(st,-1);

    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}