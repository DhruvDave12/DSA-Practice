#include <bits/stdc++.h>
using namespace std;

long findMaximumSum(vector<int> stockPrice, int k) {
    // we have to take continuous groups of k with distinct elements
    set<int> st;
    int sum = 0;
    int res = -1;
    
    for(int i=0; i<stockPrice.size(); i++){
        int y = st.size();
        st.insert(stockPrice[i]);
        if(st.size() > y){
            sum += stockPrice[i];
        }    
        if(st.size() == k){
            st.clear();
            res = max(res, sum);
        }
    }

    return res;
}

int countWindowDistinct(int win[], int K)
{
    int dist_count = 0;
 
    // Traverse the window
    for (int i = 0; i < K; i++) {
        // Check if element arr[i] exists in arr[0..i-1]
        int j;
        for (j = 0; j < i; j++)
            if (win[i] == win[j])
                break;
        if (j == i)
            dist_count++;
    }
    return dist_count;
}

int helper(int arr[], int N, int K){
    for (int i = 0; i <= N - K; i++)
        cout << countWindowDistinct(arr + i, K) << endl;
}
long findMaximumSum(vector<int> stockPrice, int k) {
    // we have to take continuous groups of k with distinct elements
    // set<int> st;
    map<int, int> mp;
    long sum = 0;
    long res = -1;
    for(int i=0; i<stockPrice.size(); i++){
        // st.clear();
        sum = 0;
        for(int j=i; j<i+k && j<stockPrice.size(); j++){
            // int y = st.size();
            // st.insert(stockPrice[j]);
            mp[stockPrice[j]] = stockPrice[j];
            // if(st.size() <= y) break;
        }

        if(mp.size() == k){
            for(auto it: mp){
                sum += it.second;
            }
           
            res = max(res, sum);
        } 
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {1,2,7,7,4,3,6};
    long ans = findMaximumSum(vec, 3);

    cout<<ans<<"\n";
    return 0;
}
