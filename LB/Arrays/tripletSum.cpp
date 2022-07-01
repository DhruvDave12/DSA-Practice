#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    if(n < 3){
        return false;
    }
    sort(A, A+n);
    int left, right;

    for(int i=0; i<n-2; i++){
        left = i+1;
        right = n-1;
        while(left<right){
            if(A[i] + A[left] + A[right] == X){
                return true;
            }
            else if(A[i] + A[left] + A[right] > X){
                right--;
            }
            else{
                left++;
            }
        }
    }
    return false; 
}
// 1 4 6 8 10 45
// 1 2 3 4 6
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}