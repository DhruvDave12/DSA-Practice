#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> check(26, 0);

        string s;
        cin>>s;

        int temp = 0;
        for(int i=0; i<s.length(); i++){
            int idx = s[i] - 'A';
            if(check[idx] == 0){
                temp += 2;
                check[idx] = 1;
            } else temp++;
        }

        cout<<temp<<"\n";
    }
    return 0;
}