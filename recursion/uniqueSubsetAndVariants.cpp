#include <bits/stdc++.h>
using namespace std;

// global set to store unique elements in set
set<string> st;

// Instead of set i can use map and vectors but that would take more memory.

void solve(string input, string output){
    if(input == ""){
        st.insert(output);
        return;
    }
    string output1 = output;
    string output2 = output;

    output2.push_back(input[0]);
    input.erase(input.begin() + 0);
    solve(input, output1);
    solve(input, output2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    string output = "";
    cin>>input;

    solve(input, output);

    set<string> :: iterator it;
    for(it = st.begin(); it != st.end(); it++){
        cout<<*it<<"\n";
    }

    return 0; 
}

// Substring me order matters
// Subset me order doesnt matter
// Subsequence means continuous part of a string
