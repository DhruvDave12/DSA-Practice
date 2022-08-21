#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checker(string s){
        map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        bool flag = false;
        for(int i=0; i<s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                flag = true;
                char toFind = s[i] - 32;
                if(mp.count(toFind) == 0) return false;
            }
        }

        if(flag) return true;
        // return true;
        return false;
    }

    string longestNiceSubstring(string s) {
        string temp = "";
        string res;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                temp += s[j];
                if(checker(temp) && temp.length() > res.length()){
                    res = temp;
                }
            }
            temp = "";
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "jcJ";

    Solution st;
    cout<<st.longestNiceSubstring(s)<<"\n";
    return 0;
}