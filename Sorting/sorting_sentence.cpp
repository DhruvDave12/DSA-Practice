#include <bits/stdc++.h>
using namespace std;

// Using Ordered Map
class Solution {
public:
    string sortSentence(string s) {
        int len = s.length();
        map<int, string> mp;
        string temp = "";

        for(int i=0; i<len; i++){
            if(s[i] == ' '){
                mp[s[i-1]-'0'] = temp;
                temp = "";
            }
            if(s[i] != ' '){
                temp = temp + s[i];
            }

            if(i == len-1){
                mp[s[i]-'0'] = temp;
            }
        }   

        map<int,string> :: iterator it;

        string toReturn = "";
        for(it = mp.begin(); it != mp.end(); it++){
            it->second.pop_back();
            toReturn += it->second;
            toReturn += " ";
        }

        toReturn.pop_back();
        return toReturn;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution s;
    string ans = s.sortSentence("is2 sentence4 This1 a3");
    cout<<ans<<"\n";
    return 0;
}