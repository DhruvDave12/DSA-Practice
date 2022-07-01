#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    map<int,int> mp;
    int target = n/k;

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    vector<int> ans;

    map<int,int> :: iterator it;
    for(it = mp.begin(); it!=mp.end(); it++){
        if(it->second > target){
            ans.push_back(it->first);
        }
    }

    // ans output
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}