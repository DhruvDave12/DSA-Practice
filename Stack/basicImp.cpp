#include <bits/stdc++.h>
using namespace std;

class MeriStack {
    public:
    vector<int> vec;
    int sizee;

    MeriStack(){
        vec.clear();
        this->sizee = 0;
    }

    void push(int ele){
        vec.push_back(ele);
        sizee++;
    }

    int pop(){
        if(vec.size() > 0){
            int res = vec[vec.size()-1];
            vec.pop_back();
            sizee--;
            return res;
        }
        return -1;
    }
    int top(){
        if(vec.size() > 0){
            return vec[vec.size()-1];
        }
        return -1;
    }

    int size(){
        return sizee;
    }

    bool empty(){
        if(sizee == 0) return true;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    MeriStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    while(!st.empty()){
        int x = st.top();
        cout<<x<<"\n";
        st.pop();
    }

    return 0;
}