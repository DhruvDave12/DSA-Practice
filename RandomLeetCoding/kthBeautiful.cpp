#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        string st = "";
        int count = 0;
        for(int i=0; i<k; i++){
            st += s[i];
        }

        int x = stoi(st);
        // cout<<"X: "<<x<<"\n";
        if(num%x == 0) count++;
        cout<<"ST: "<<st<<"\n";

        for(int i=k; i<s.length(); i++){
            st.erase(0, 1);
            st += s[i];
            x = stoi(st);
            cout<<"ST: "<<st<<"\n";
            // cout<<"X: "<<x<<"\n";
    
            if(num%x == 0) count++;
        } 

        return count;

    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 430043;
    int k = 2;

    Solution s;
    cout<<s.divisorSubstrings(n, k)<<"\n";
    return 0;
}