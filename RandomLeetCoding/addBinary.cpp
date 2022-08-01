#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.length()-1, j = b.length()-1;
        int currSum = 0;
        string ans = "";

        while(i>= 0 && j >= 0){
            currSum = 0;
            currSum += ((a[i]-'0') + (b[j]-'0') + carry);
            if(currSum == 2){
                carry = 1;
                currSum = 0;
            }
            else if(currSum == 3){
                carry = 1;
                currSum = 1;
            }
            else {
                carry = 0;
            }
            // cout<<currSum<<" ";
            ans.push_back(currSum + '0');
            i--;
            j--;
        }

        if(i>=0){
            while(i >= 0){
                currSum = 0;
                currSum = ((a[i]-'0') + carry);
                if(currSum == 2){
                    carry = 1;
                    currSum = 0;
                }
                else if(currSum == 3){
                    carry = 1;
                    currSum = 1;
                }
                else{
                    carry = 0;
                }
                // cout<<currSum<<" ";
                ans.push_back(currSum + '0');
                i--;
            }
        }
        if(j>=0){
            while(j >= 0){
                currSum = 0;
                currSum = ((b[j]-'0') + carry);
                if(currSum == 2){
                    carry = 1;
                    currSum = 0;
                }
                else if(currSum == 3){
                    carry = 1;
                    currSum = 1;
                }
                else{
                    carry = 0;
                }
                // cout<<currSum<<" ";
                ans.push_back(currSum + '0');
                j--;
            }
        }

        if(carry == 1){
            ans.push_back(carry + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a = "1010";
    string b = "1011";

    Solution s;
    string ans = s.addBinary(a,b);

    cout<<ans<<"\n";
    return 0;
}