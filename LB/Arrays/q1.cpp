#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &vec){
    for(int i=0; i<vec.size()/2; i++){
        int temp = vec[i];
        vec[i] = vec[vec.size()-i-1];
        vec[vec.size()-i-1] = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {1,2,3};

    reverseArray(vec);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}