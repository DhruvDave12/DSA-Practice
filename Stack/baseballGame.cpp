#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,bool> getInt(string s){
        int res = 0;    
        int id = 0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]-'0' >= 0 && s[i]-'0' <= 9){
                res = res + (s[i]-'0')*pow(10,id);
                id++;
            } else {
                return make_pair(-1, false);
            }
        }

        return make_pair(res,true);
    }
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i=0; i<ops.size(); i++){
            pair<int,bool> p = getInt(ops[i]);
            if(p.second){
                st.push(p.first);
            } else {
                if(ops[i] == "C"){
                    st.pop();
                } 
                else if(ops[i] == "D"){
                    int x = st.top();
                    x = 2*x;
                    st.push(x);
                } 
                else if(ops[i] == "+"){
                    int first = st.top();
                    st.pop();
                    int second = st.top();
                    st.pop();

                    int toPush = first+second;
                    st.push(second);
                    st.push(first);
                    st.push(toPush);
                }
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}