#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int energyReq = 0, expRequired = 0;
        int energyHours = 0, expHours = 0;

        for(int i=0; i<energy.size(); i++){
            energyReq += energy[i];
        }
        energyReq++;
        if(energyReq > initialEnergy){
            energyHours=energyReq-initialEnergy;
        }
        // int temp = INT_MIN;
        // int maxIdx = 0;
        // for(int i=0; i<experience.size(); i++){
        //     if(experience[i] > temp){
        //         temp = experience[i];
        //         maxIdx = i;
        //     }
        // }

        // int s = 0;
        // for(int i=0; i<maxIdx; i++){
        //     s += experience[i];
        // }
        // s += initialExperience;
        // if(temp > s){
        //     expHours = (temp-s) + 1;
        // }
        int s = initialEnergy;
        int req = 0;
        if(s <= experience[0]){
            s += experience[0]+1;
            req += (experience[0]-s)+1;
        }
        for(int i=1; i<experience.size(); i++){
            if(s+experience[i-1] <= experience[i]){
                req = experience[i]-(s+experience[i-1]) + 1;
                s = experience[i]+(s+experience[i-1]) + 1;
            }
        }
        energyHours = req;
        return expHours + energyHours;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}