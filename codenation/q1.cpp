#include <bits/stdc++.h>
using namespace std;

int solver(vector<int> &A, int B){
    map<int,int> mp;
    // sort(A.begin(), A.end());
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0; i<A.size(); i++){
        pq.push(A[i]);
        mp[A[i]] = 0;
    }
    
    int efforts = 0;

    for(int i=0; i<A.size(); i++){
        int min = pq.top();
        cout<<"FIRST MIN: "<<min<<"\n";
        pq.pop();
        if(mp[min] < B){
            efforts += min;
            mp[min]++;
            int x = pq.top();
            pq.pop();
            x = x + min;
            pq.push(x);
        }
        else{
            pq.pop();
        }
    }
    return efforts;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> A = {3,2,1,10};
    int B = 2;

    cout<<solver(A,B)<<"\n";
    return 0;
}