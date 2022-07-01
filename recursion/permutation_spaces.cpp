#include <bits/stdc++.h>
using namespace std;

void solver(string input, string output){
    if(input.length() == 0){
        cout<<output<<"\n";
        return;
    }
    string output1 = output;
    string output2 = output;
    // case 1 without _
    output1.push_back(input[0]);
    // case 2 with spaces
    output2.push_back('_');
    output2.push_back(input[0]);

    // erasing from input
    input.erase(input.begin() + 0);

    // calling for new input and output
    solver(input, output1);
    solver(input, output2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    string output = "";
    cin>>input;

    output.push_back(input[0]);
    input.erase(input.begin() + 0);

    solver(input, output);

    return 0;
}