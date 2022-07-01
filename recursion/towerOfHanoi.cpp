#include <bits/stdc++.h>
using namespace std;

void stepsForTowerOfHanoi(int n, char A, char B, char C){
    if(n == 0){
        return;
    }
    stepsForTowerOfHanoi(n-1, A, C, B);
    cout<<"Move from "<<A<<" to "<<C<<"\n";
    stepsForTowerOfHanoi(n-1, B, A, C);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stepsForTowerOfHanoi(2, 'A', 'B', 'C');
    return 0;
}