#include <bits/stdc++.h>
using namespace std;

// We can find count of inversions using the merge sort technique.
// In merge sort when we merge the arrays at that time the unsorted part counts as an inversion
int _merge(vector<int> &vec, int low, int mid, int high, vector<int> &temp){
    int inv_count = 0;
    int i = low;
    int j = mid;
    int k = low;

// NUMS
// left - mid -> left vector
// mid-high -> right vector

    while((i <= mid-1) && (j<=high)){
        if(vec[i] <= vec[j]){
            temp[k++] = vec[i++];
        }
        else{
            temp[k++] = vec[j++];
            // here we are crossing from right to left
            // so we keep this inv_count
            inv_count  = inv_count + (mid - i);
        }
    }
    while(i<=mid-1){
        temp[k++] = vec[i++];
    }
    while(j<=high){
        temp[k++] = vec[j++];
    }
    for(int i=low; i<=high; i++){
        vec[i] = temp[i];
    }

    return inv_count;
}

int _mergeSort(vector<int> &vec, int low, int high, vector<int> &temp){
    int mid, inv_count = 0;
    if(high > low){
        mid = (high + low) / 2;
        // T(N) = T(N/2) + N -> O(NlogN)

        // breaking vector into halves
        inv_count += _mergeSort(vec, low, mid, temp);
        inv_count += _mergeSort(vec, mid+1, high, temp);
        
        // merging those halves
        inv_count += _merge(vec, low, mid+1, high, temp);
    }
    return inv_count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}