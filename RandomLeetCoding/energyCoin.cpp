#include <bits/stdc++.h>
using namespace std;


// int getRich(long initialEnergy, vector<int>& energy, vector<int> &coins){
//     int i = 1;
//     int coin = 0;
//     if(initialEnergy < energy[0]){
//         initialEnergy += energy[0];
//     } else {
//         coin += coins[0];
//     }
//     while(i < energy.size()){
//         if(initialEnergy < energy[i]){
//             initialEnergy += energy[i];
//             initialEnergy--;
//         } else {
//             coin += coins[i];
//             initialEnergy--;
//         }
//         i++;
//     }

//     return coin;
// }

vector<int> getOriginalArray(vector<int> pref){
    vector<int> res;
    res.push_back(pref[0]);
    int prefXor = pref[0];

    for(int i=1; i<pref.size(); i++){
        res.push_back(prefXor ^ pref[i]);
        prefXor = prefXor ^ res[i];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> energy = {2,1,1};
    vector<int> coins = {11,5,7};

    int initalEnergy = 0;
    
    // int ans = getRich(initalEnergy, energy, coins);

    cout<<ans<<"\n";
    return 0;
}