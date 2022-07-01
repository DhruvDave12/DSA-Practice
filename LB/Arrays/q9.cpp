#include <bits/stdc++.h>
using namespace std;


int minJumps(vector<int> &vec){
   int stepsCanMove = vec[0];
   int maxReachablePoint = vec[0];
   int jumps = 1;

   if(vec[0] == 0){
        return -1;
   }
   if(vec.size() == 1){
        return 0;
   }

   for(int i=1; i<vec.size(); i++){
        if(i == vec.size()-1){
            return jumps;
        }
        // updating maxR at each step;
        maxReachablePoint = max(maxReachablePoint, i+vec[i]);
        stepsCanMove--;
        if(stepsCanMove == 0){
            jumps++;
            if(i >= maxReachablePoint){
                return -1;
            }
            stepsCanMove = maxReachablePoint - i;
        }
   }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;cin>>n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    int ans = minJumps(vec);
    cout<<"MIN JUMPS: "<<ans<<"\n";

    // KADANE ALGORITHM
    
    // int maxSoFar = INT_MIN;
    // int maxHere = 0;
    // for(int i=0; i<vec.size(); i++){
    //     maxHere += vec[i];

    //     if(maxHere > maxSoFar){
    //         maxSoFar = maxHere;
    //     }
    //     else if(maxHere < 0){
    //         maxHere = 0;
    //     }
    // }
    return 0;
}