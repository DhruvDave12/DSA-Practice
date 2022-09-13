#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		string all_longest_common_subsequences(string s, string t)
		{
            vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
            for(int i=0;i<dp.size(); i++){
                for(int j=0; j<dp[i].size(); j++){
                    if(i==0 || j == 0) dp[i][j] = 0;
                }
            }

            for(int i=1; i<dp.size(); i++){
                for(int j=1; j<dp[i].size(); j++){
                    if(s[i-1] == t[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }

            int n = s.size(), m = t.size(); 
            string output = "";

            while(n > 0 && m > 0){
                if(s[n-1] == t[m-1]){
                    output.push_back(s[n-1]);
                    n--;
                    m--;
                } else{
                    if(dp[n][m-1] > dp[n-1][m]){
                        m--;
                    } else{
                        n--;
                    }
                }
            }
            reverse(output.begin(),output.end());
            return output;
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string x = "acbcf";
    string y = "abcdaf";

    string s = Solution().all_longest_common_subsequences(x,y);
    cout<<"ANS: "<<s<<"\n";
    return 0;
}