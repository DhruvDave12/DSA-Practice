#include <bits/stdc++.h>
using namespace std;

// Time complexity O(N), space complexity O(1)

void moveAllNegativeFirst(vector<int> &vec){
    // here we can partition the vector into two parts unlike three in last question
    int low = 0;
    int mid = 0;

    while(mid < vec.size()){
        if(vec[mid] < 0){
            swap(vec[mid], vec[low]);
            low++;
            mid++;
        }
        else{
            mid++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

    moveAllNegativeFirst(vec);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}