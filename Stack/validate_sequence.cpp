#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<int> st;
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int firstPopped = popped[0];
        int firstPoppedIdx = 0;
        for(int i=0; i<pushed.size(); i++){
            if(pushed[i] != firstPopped){
                st.push(pushed[i]);
            }
            else{
                firstPoppedIdx = i;
                break;
            }
        }

        // now we check the cases;
        // cout<<firstPoppedIdx<<"\n";
        int k=1;
        bool found = false;
        int allSameShould = 0;
        
        for(int j = firstPoppedIdx+1; j<pushed.size(); j++){
            if(pushed[j] != popped[k]){
                st.push(pushed[j]);
                k++;
            }
            else{
                k++;
            }
        }
        
        int x = 0;
        for(int i=0; i<popped.size(); i++){
            if(popped[i] == st.top()){
                x = i;
                break;
            }
        }
        if(st.size() != popped.size()-x){
            return false;
        }
        // cout<<k<<"\n";
        for(int i=x; i<popped.size(); i++){
            if(st.empty()){
                return false;
            }
            if(popped[i] != st.top()){
                return false;
            }
            else{
                st.pop();
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution s;
    vector<int> A = {0,2,1};
    vector<int> B = {0,1,2};

    if(s.validateStackSequences(A,B)){
        cout<<"TRUE"<<"\n";
    }
    else{
        cout<<"FALSE"<<"\n";
    }
    return 0;
}