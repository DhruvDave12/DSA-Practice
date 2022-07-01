#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // max positive product
    // ending at the current position
    int max_ending_here = arr[0];
 
    // min negative product ending
    // at the current position
    int min_ending_here = arr[0];
 
    // Initialize overall max product
    int max_so_far = arr[0];
    /* Traverse through the array.
    the maximum product subarray ending at an index
    will be the maximum of the element itself,
    the product of element and max product ending previously
    and the min product ending previously. */
    for (int i = 1; i < n; i++)
    {
        int temp = max({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        min_ending_here = min({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        max_ending_here = temp;
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Solution s;
    int ans = s.maxProduct(arr, n);
    cout<<"ANS: "<<ans<<"\n";
    return 0;
}