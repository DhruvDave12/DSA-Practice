#include <bits/stdc++.h>
using namespace std;

// O(N)
int unionSize(vector<int> &v1, vector<int> &v2){
    map<int,bool> mp;
    int count = 0;
    for(int i=0; i< v1.size(); i++){
        mp[v1[i]] = true;
        count++;
    }

    for(int i=0; i<v2.size(); i++){
        if(!mp[v2[i]]){
            count++;
            mp[v2[i]] = true;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    vector<int> vec1(n);
    vector<int> vec2(m);

    for(int i=0; i<n; i++){
        cin>>vec1[i];
    }
    for(int i=0; i<m; i++){
        cin>>vec2[i];
    }


    int ans = unionSize(vec1, vec2);

    cout<<"ANS: "<<ans<<"\n";
    return 0;
}