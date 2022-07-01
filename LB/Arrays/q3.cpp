#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &vec, int k){
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<vec.size(); i++){
        pq.push(vec[i]);
    }

    int temp = 0;
    int ans = pq.top();
    while(!pq.empty()){
        if(temp == k){
            break;
        }
        ans = pq.top();
        temp++;
        pq.pop();
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {7,10,4,3,20,15};
    int k = 3;

    int ans = kthSmallest(vec, k);
    cout<<ans<<" ";
    return 0;
}