#include <bits/stdc++.h>
using namespace std;

void sortOs1s2s(vector<int> &vec){
    map<int,int> mp;
    for(int i=0; i<vec.size(); i++){
        mp[vec[i]]++;
    }

    for(int i=0; i<mp[0]; i++){
        vec[i] = 0;
    }
    for(int i=mp[0]; i<mp[1]; i++){
        vec[i] = 1;
    }
    for(int i=mp[1]; i<mp[2]; i++){
        vec[i] = 2;
    }

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
}

void sortArrayOf012(vector<int> &vec){
    // O(N) sorting best way of doing by dividing the array into three parts low mid high storing 0, 1 and 2 respectively.
    
    int low = 0;
    int mid = 0;
    int high = vec.size()-1;
    while(mid < high){
        switch(vec[mid]){
            case 0:
                swap(vec[low], vec[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(vec[mid], vec[high]);
                high--;
                break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {0,2,1,2,0};
    // We can divide the vector into 3 parts 
    // 0 0 1 2 2
    // middle section consists of 1's
    // start section consists of 0's
    // end section consists of 2's

    // sortOs1s2s(vec);
    sortArrayOf012(vec);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}