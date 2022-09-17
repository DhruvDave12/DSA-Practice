#include <bits/stdc++.h>
using namespace std;

int getMidElement(stack<int> &st, int size){
    // int x = st.size();
    if(st.size() == ceil((float)size/2)){
        return st.top();
    }
    int x = st.top();
    st.pop();
    getMidElement(st,size);
    // st.push(x);
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

    int ans = getMidElement(st,st.size());
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}