#include <bits/stdc++.h>
using namespace std;

// Time Complexity -> O(N)
void reverseArray(int arr[], int start, int end){
    while(end > start){
        int temp = arr[end];
        arr[end] = arr[start];
        arr[start] = temp;
        end--;
        start++;
    }
}

void solver(int arr[], int n, int d){
    int part1 = d;
    int part2 = n-d;

    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d;
    cin>>n>>d;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    solver(arr, n, d);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}