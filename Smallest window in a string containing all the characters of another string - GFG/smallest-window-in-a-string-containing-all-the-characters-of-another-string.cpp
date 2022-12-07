//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        map<char,int> mp;
        
        int ans = INT_MAX;
        int count = 0;
        int start = 0;
        
        for(int i=0; i<p.length(); i++){
            if(mp[p[i]] == 0) count++;
            mp[p[i]]++;
        }
        
        int i = 0;
        int j = 0;
        
        while(j < s.length()){
            mp[s[j]]--;
            if(mp[s[j]] == 0) count--;
            
            // when all ends
            if(count == 0){
                while(count == 0){
                    if(ans > j-i+1){
                        ans = min(ans,j-i+1);
                        start = i;
                    }
                    
                    mp[s[i]]++;
                    if(mp[s[i]] > 0){
                        count++;
                    }
                    
                    i++;
                }
            }
            j++;
        }
        
        
        if(ans != INT_MAX){
            return s.substr(start,ans);
        } 
        
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends