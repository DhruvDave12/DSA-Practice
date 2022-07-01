#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> notInArr2;
        map<int,bool> arr2Map;
        vector<int> inSortOrder;

        for(int i=0; i<arr2.size(); i++){
            arr2Map.insert({arr2[i], true});
        }

       
        for(int i=0; i<arr2.size(); i++){
            for(int j=0; j<arr1.size(); j++){
                if(arr1[j] == arr2[i]){
                    inSortOrder.push_back(arr1[i]);
                }
            }
        }
        
        for(int i=0; i<arr1.size(); i++){
            if(!arr2Map[arr1[i]]){
                notInArr2.push_back(arr1[i]);
            }
        }

        vector<int> ans;
        for(int i=0; i<inSortOrder.size(); i++){
            ans.push_back(inSortOrder[i]);
        }

        sort(notInArr2.begin(), notInArr2.end());
        for(int i=0; i<notInArr2.size(); i++){
            ans.push_back(notInArr2[i]);
        }

        return ans;
        // now we will sort and add it to the last of our relative sorted array

        // // Now comes the logic for relative sorted array
        // map<int,int> :: iterator itr;
        // vector<pair<int,pair<int,bool>>> vec;

        // for(itr = arr2Map.begin(); itr != arr2Map.end(); itr++){
        //     vec.push_back({itr->first, {itr->second, true}});
        //     // cout<<itr->first<<" "<<itr->second<<"\n";
        // }

        // sort(vec.begin(), vec.end(), [] (const auto &x, const auto &y) { return x.second < y.second; });
        // sort(arr1.begin(), arr1.end());

        // for(int i=0; i<vec.size(); i++){
        //     cout<<vec[i].first<<" "<<vec[i].second.first<<" "<<vec[i].second.second<<"\n";
        // }
        
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};

    s.relativeSortArray(arr1, arr2);
    return 0;
}