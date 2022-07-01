#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin>>q;

    while(q--){
        int n;
        cin>>n;
        string s;
        string t;
        cin>>s;
        cin>>t;

        bool flag = false;
        int ans = 0;
        int notSame = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] != t[i]){
                notSame++;
            }
        }

        for(int i=0; i<s.length(); i++){
            if(s[i] != t[i] && flag == false && ((s[i] == 'a' && t[i] == 'b') || (s[i] == 'b' && t[i] == 'c'))){
                flag = true;
            }
            else if(s[i] != t[i] && flag == true && ((s[i] == 'b' && t[i] == 'a') || (s[i] == 'c' && t[i] == 'b'))){
                flag = false;
                ans++;
            }
        }
        if(notSame%2 == 0 && notSame/2 == ans){
            cout<<"YES"<<"\n";
        } else {
            if(notSame%2 != 0 && s == t){
                cout<<"YES"<<"\n";
            }
            else{
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}