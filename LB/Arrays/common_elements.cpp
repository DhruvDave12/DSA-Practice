#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public: 
    vector<int> ans;   
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            map<int,bool> mp;
            map<int, bool> mp2;
            map<int, bool> alreadyInserted;
            
            for(int i=0; i<n1; i++){
                mp[A[i]] = true;
            }
            
            for(int i=0; i<n2; i++){
                if(mp[B[i]]){
                    // means it has come in A array so we keep it aside in different map;
                    mp2[B[i]] = true;
                }
            }

            for(int i=0; i<n3; i++){
                if(mp2[C[i]] && !alreadyInserted[C[i]]){
                    // means it has came in all three
                    ans.push_back(C[i]);
                    alreadyInserted[C[i]] = true;
                }
            }

            return ans;
        }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}