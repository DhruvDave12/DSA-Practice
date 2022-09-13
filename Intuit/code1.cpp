#include <bits/stdc++.h>
using namespace std;


string solver(char res[], int n){
    string ans = "";
    if(n==2){
        ans.push_back('W');
        return ans;
    }
    
    for(int i=1; i<n-1; i++){
        if(res[i] == '_'){
            ans.push_back('W');
        }
        else if(res[i] == '*'){
            while(res[i] == '*'){
                i++;
            }
            ans.push_back('J');
        }
    }

    if(n>=2 && res[n-2] == '_'){
        ans.push_back('W');
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;cin>>n;
    char arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    string ans = solver(arr, n);

    cout<<ans<<"\n";
    return 0;
}