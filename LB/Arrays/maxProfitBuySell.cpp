#include <bits/stdc++.h>
using namespace std;

// int getMaxDiff(vector<int> &vec, int start, int end){
//     if(end > vec.size()-1 || start < 0 || start > vec.size()-1 || end < 0){
//         return -1;
//     }
//     stack<int> st;
//     st.push(vec[end]);
//     int maxDiff = INT_MIN;
//     for(int i=end-1; i>=start; i--){
//         if(vec[i] > st.top()){
//             st.pop();
//             st.push(vec[i]);
//         }
//         else{
//             maxDiff = max(maxDiff, st.top()-vec[i]);
//         }
//     }
//     return maxDiff;
// }

 
int maxtwobuysell(vector<int> &arr,int size) {
    int first_buy = INT_MIN;
      int first_sell = 0;
      int second_buy = INT_MIN;
      int second_sell = 0;
       
      for(int i=0;i<size;i++) {
         
          first_buy = max(first_buy,-arr[i]);//we set prices to negative, so the calculation of profit will be convenient
          first_sell = max(first_sell,first_buy+arr[i]);
          second_buy = max(second_buy,first_sell-arr[i]);//we can buy the second only after first is sold
          second_sell = max(second_sell,second_buy+arr[i]);
       
    }
     return second_sell;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;cin>>n;

    vector<int>prices(n);
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    // stack<int> st;
    // st.push(prices[prices.size()-1]);

    // int maxIdx = prices.size()-1;
    // int minIdx = 0;
    // int maxDiff = INT_MIN;
    // for(int i=prices.size()-2; i>=0; i--){
    //     if(prices[i] > st.top()){
    //         maxIdx = i;
    //         st.pop();
    //         st.push(prices[i]);
    //     }
    //     else{
    //         if(st.top() - prices[i] > maxDiff){
    //             maxDiff = st.top() - prices[i];
    //             minIdx = i;
    //         }
    //     }
    // }

    // int greatest = maxDiff;
    // int leftGreat = getMaxDiff(prices, 0, minIdx-1);
    // int rightGreat = getMaxDiff(prices, maxIdx+1, prices.size()-1);

    // int ans = greatest + max(leftGreat, rightGreat);

    cout<<"ANS: "<<maxtwobuysell(prices, n)<<"\n";
    return 0;
}