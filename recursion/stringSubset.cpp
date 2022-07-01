#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output){
    // make the recursive tree and solve
    if(input.length() == 0){
        // we are at the leaf node
        cout<<output<<" ";
        return;
    }

    // two branches
    string output1 = output;
    string output2 = output;
    // now we take decision
    // we take the element in output2 and not in output1
    output2.push_back(input[0]);
    // removing first element from the input string
    input.erase(input.begin() + 0);
    solve(input, output1);
    solve(input, output2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    cin>>input;

    string output = "";
    solve(input, output);
    
    return 0;
}