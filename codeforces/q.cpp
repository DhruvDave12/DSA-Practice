#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q;
    cin>>n>>q;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    vector<int> arrSUm(n);
    arrSUm = arr;
    for(int i=1; i<arrSUm.size(); i++){
        arrSUm[i] = arrSUm[i] + arrSUm[i-1];
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        int ans = 0;
        if(x==y && x != arr.size()){
            x++;
        }
        ans = arrSUm[x-1] - arrSUm[x-y-1];
        if(x==y && x == arr.size()){
            ans = arrSUm[arrSUm.size()-1];   
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}

// 5 5 3 2 1
// 5 10 13 15 16

// presum(x-1) - presum(x-y-1)