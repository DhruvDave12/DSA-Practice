#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Kadane's Algorithm
    int n; cin>>n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    // Simple idea of kadane algo is to kepe the track of maximum sum we get till now
    
    int maxSoFar = INT_MIN, maxEnding = 0;

    for(int i=0; i<vec.size(); i++){
        maxEnding += vec[i];
        if(maxEnding > maxSoFar){
            maxSoFar = maxEnding;
        }
        if(maxEnding < 0){
            maxEnding = 0;
        }
    }

    cout<<"MAX CONTIGUOUS SUBARRAY SUM: "<<maxSoFar<<"\n";
    return 0;
}