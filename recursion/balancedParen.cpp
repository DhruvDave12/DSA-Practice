#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void getAllBalanced(int open, int close, string output){
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }
    if(open != 0){
        // open parenthesis always available
        string output1 = output;
        output1.push_back('(');
        getAllBalanced(open-1, close, output1);
    }

    if(close > open){
        string output2 = output;
        output2.push_back(')');
        getAllBalanced(open, close-1, output2); 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    getAllBalanced(n,n,"");
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}