#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    set<int> st;
    vector<int> vec;
    int findLongestConseqSubseq(int arr[], int n)
    {
        for(int i=0; i<n; i++){
            cout<<arr[i]<<"\n";
            st.insert(arr[i]);
        }
        set<int> :: iterator it;
        for(it = st.begin(); it!=st.end(); it++){
            cout<<"IT: "<<*it<<"-";
           vec.push_back(*it);
        }
        int count = 1;
        int maxx = 1;
        for(int i=0; i<vec.size()-1; i++){
            cout<<vec[i]<<",";
            if(vec[i+1]-vec[i] == 1){
                count++;
            }
            else{
                maxx = max(maxx, count);
                count = 1;
            }
        }

        maxx = max(maxx, count);
        return maxx;
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Solution s;
    int arr[] = {9,9,3,3,2,2,1,1,4,4,5,5,6,6,6,6,8};
    int ans = s.findLongestConseqSubseq(arr, 17);

    cout<<"ANS: "<<ans<<"\n";
    return 0;
}