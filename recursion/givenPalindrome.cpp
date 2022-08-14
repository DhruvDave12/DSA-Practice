#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s){
    if(s.length() <= 1) return true;

    for(int i=0; i<s.length()/2; i++){
        if(s[i] != s[s.length()-i-1]) return false; 
    }
    return true;
}

void getAllPalindromes(string s, string output, set<string>& vec){
    if(s.length() == 0){
        if(checkPalindrome(output)) vec.insert(output);
        return;
    }
    string o1 = output;
    string o2 = output;
    o1.push_back(s[0]);
    s.erase(s.begin()+0);
    getAllPalindromes(s, o1, vec);
    getAllPalindromes(s, o2, vec);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set<string> st;
    string s = "hellehdadmom";

    getAllPalindromes(s, "", st);

    // for(auto &str: st){
    //     cout<<str<<"\n";
    // }

    cout<<st.size()<<"\n";
    return 0;
}