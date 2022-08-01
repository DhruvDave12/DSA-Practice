#include <bits/stdc++.h>
using namespace std;

// May not work for large testcases
class Solution {
public:
    vector<long long> ans;
    
    long long getDecimal(string s){
        long long res = 0;
        long long x = 0;
        
        for(int i=s.length()-1; i>=0; i--){
            long long z = s[i] - '0';
            res = res + (z*(round(pow(2,x))));
            x++;
        }
        
        return res;
    }
    void fillVector(vector<string> vec){
        for(int i=0; i<vec.size(); i++){
            long long z = getDecimal(vec[i]);
            ans.push_back(z);
        }
    }
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<string> vec;
        string temp = "";
        
        for(int i=0; i<nums.size(); i++){
            temp.push_back(nums[i] + '0');
            vec.push_back(temp);
        }
        
        fillVector(vec);
        
        vector<bool> finalRes;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<"\n";
            if(ans[i] % 5 == 0){
                finalRes.push_back(true);
            }
            else{
                finalRes.push_back(false);
            }
        }
        
        return finalRes;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}