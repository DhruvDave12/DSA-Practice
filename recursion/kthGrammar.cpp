#include <bits/stdc++.h>
using namespace std;

// we are given a base condition like n==1 and k==1 so return 0
// else we have to generate grammar

/*      k=1 ...........
    N=1 0
    N=2 0 1
    N=3 0 1 1 0
    N=4 0 1 1 0 1 0 0 1
*/

int kthGrammarGenerator(int n, int k){
    if(n==1 && k==1){
        return 0;
    }

    int mid = pow(2, n-1) / 2;
    if(k <= mid){
        return kthGrammarGenerator(n-1, k);
    }
    return !kthGrammarGenerator(n-1, k-mid);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}