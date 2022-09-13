#include <bits/stdc++.h>
using namespace std;

int deleteProducts(vector<int> ids, int m){
    unordered_map<int,int> mp;
    for(int i=0; i<ids.size(); i++){
        mp[ids[i]]++;
    }
    vector<pair<int,int>> vec;

    for(auto it: mp){
        vec.push_back({it.second, it.first});
    }
    sort(vec.begin(), vec.end());
    int size = vec.size();
    int x = 0;
    for(int i=0; i<vec.size(); i++){
        if(vec[i].first <= m){
            m -= vec[i].first;
            x++;
        } else return size-x;
    }

    return size - x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> idx = {1,1,1,2,3,2};
    int m = 2;

    int ans = deleteProducts(idx, m);

    cout<<"ANS: "<<ans<<"\n";
    return 0;
}   