#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

// these binary numbers will have all prefixes with # 1's >= # 0's
void getAllBinaryPrefix(int ones, int zeroes, string output, int n){
    if(n == 0){
        ans.push_back(output);
        return;
    }
    string output1 = output;
    output1.push_back('1');
    getAllBinaryPrefix(ones+1, zeroes, output1, n-1);
    if(zeroes < ones){
        string output2 = output;
        output2.push_back('0');
        getAllBinaryPrefix(ones, zeroes+1, output2, n-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    getAllBinaryPrefix(0,0,"",n);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}