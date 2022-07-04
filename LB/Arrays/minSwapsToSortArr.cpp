#include <bits/stdc++.h>
using namespace std;

// now here we store the vector elements and their position and then sort the array
// now we get that vec[i].first must be there but it is on vec[i].second
// So imagine it as a graph connected between i and j such that they are supposed to be swapped
// so we get these cycles and 
// cycle - 1 for all elements is the answer

int minSwapsToSort(vector<int>vec){
    vector<pair<int,int>> store;

    for(int i=0; i<vec.size(); i++){
        store.push_back({vec[i], i});
    }

    sort(store.begin(), store.end());

    int cycleSize = 0;
    // we are going to traverse in these graphs so we need a visiting vector
    vector<bool> vis(vec.size(), false);
    int ans = 0;
    for(int i=0; i<store.size(); i++){
        if(vis[i] || store[i].second == i){
            // if this node is visited or else the element is at its correct position after sorting so continue
            continue;
        }
        // else we traverse in these graphs and count the cycles

        int j = i;
        cycleSize = 0;
        while(!vis[j]){
            vis[j] = true;
            // going on the node to be swapped
            j = store[j].second;
            cycleSize++;
        }

        if(cycleSize > 0){
            ans += cycleSize - 1;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {1,5,4,3,2};

    int ans = minSwapsToSort(vec);

    cout<<"ANS: "<<ans<<"\n";
    return 0;
}