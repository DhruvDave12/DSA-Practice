#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int minimumRecolors(string blocks, int k) {
//         // sliding window with k window
//         int black = 0;
//         int white = 0;

//         for(int i=0; i<k; i++){
//             if(blocks[i] == 'W') white++;
//             if(blocks[i] == 'B') black++;
//         }

//         int x = 0, y = k;
//         int needed = k - black;
//         if(needed == 0){
//             return 0;
//         }
//         int ans = needed;
//         while(y < blocks.size()){
//             if(blocks[y] == 'W'){
//                 white++;
//             }
//             if(blocks[y] == 'B'){
//                 black++;
//             }
//             if(blocks[x] == 'B'){
//                 black--;
//             }
//             if(blocks[x] == 'W'){
//                 white--;
//             }
//             needed = k-black;
//             ans = min(ans, needed);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        map<int,int> mp;
        vector<int> vec;
        int zeroIdx = 0;
        int zeroCount = 0;

        // edge case for 0 or all zeroes
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0') zeroCount++;
        }
        if(zeroCount == 0 || zeroCount == s.length()) return 0;


        // edge case for checking if string is already optimized
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0') {
                zeroIdx = i;
                break;
            }
        }
        bool flag = false;
        for(int i=zeroIdx+1; i<s.length(); i++){
            if(s[i] == '1') {
                flag = true;
                break;
            }
        }
        if(!flag) return 0;

        // Here we are doing for the all cases
        int toBring = zeroIdx;
        for(int i=zeroIdx; i<s.length(); i++){
            if(s[i] == '1'){
                vec.push_back(i-toBring);
                mp[i-toBring]++;
                toBring++;
            }
        }
        
        // else we will now handle the duplicate elements
        int expectedTime = vec[vec.size()-1];

        for(auto it: mp){
            expectedTime += it.second-1;
        }

        return expectedTime;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "10101010";
    Solution st;
    int x = st.secondsToRemoveOccurrences(s);

    cout<<x<<"\n";
    return 0;
}