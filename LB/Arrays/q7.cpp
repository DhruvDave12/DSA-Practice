#include <bits/stdc++.h>
using namespace std;

// O(N) rotation in clockwise direction
void rotateClockwise(vector<int> &vec, int low, int high){
    
    // 1 2 3 4 5
    // 5 1 2 3 4
    int temp = vec[low];

    for(int i=low+1; i<high-1; i++){
        int x = vec[i];
        vec[i] = temp;
        temp = x;
    }
    int last = vec[high-1];
    vec[high-1] = temp;
    vec[low] = last;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    rotateClockwise(vec, 2, vec.size());

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }

    return 0;
}