#include <bits/stdc++.h>
using namespace std;

class myDS {
    public:
    int n;
    vector<int> vec;

    myDS(int n, vector<int> vecc){
        this->n = n;
        for(int i=0;i<vecc.size();i++){
            vec.push_back(vecc[i]);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int,vector<int>> mp;
    map<int,int> aliceSk;

    int n,m;cin>>n>>m;
    int k;cin>>k;
    vector<int> reqSkills(k);
    for(int i=0;i<k;i++) cin>>reqSkills[i];

    int l;cin>>l;
    vector<int> aliceSkills(l);
    for(int i=0;i<l;i++) {
        int t;
        cin>>t;
        aliceSkills.push_back(t);
        aliceSk[t]++;
    };

    vector<int> books(m);
    for(int i=0;i<m;i++) cin>>books[i];

    for(int i=0;i<m;i++){
        int nos;cin>>nos;
        for(int j=0;j<nos;j++) {
            int temp;cin>>temp;
            mp[books[i]].push_back(temp);
        }
    }

    // Now solution

    vector<int> skillsNeeded;
    for(int i=0; i<reqSkills.size(); i++){
        if(aliceSk.count(reqSkills[i]) == 0) skillsNeeded.push_back(reqSkills[i]);
    }

    // for(auto it: mp){
    //     for(int i=0; i<skillsNeeded.size(); i++){

    //     }
    // }
    return 0;
}