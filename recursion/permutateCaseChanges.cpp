#include <bits/stdc++.h>
using namespace std;

void solveCasePermutes(string input, string output){
    // We get answer when input becomes empty so we get it all on leaf nodes of recursive tree
    if(input.length() == 0){
        cout<<output<<" ";
        return;
    } 

    // We have two branches in the recursive tree
    string output1 = output;
    string output2 = output;

    output2.push_back(input[0]);
    output1.push_back(toupper(input[0]));
    input.erase(input.begin() + 0);

    // Now we call for more other branches
    solveCasePermutes(input, output1);
    solveCasePermutes(input, output2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // We are given a string, we have to make all permutations with case changes i.e., uppercase or lowercase
    string input;
    cin>>input;

    string output = "";

    // to print output in sorted order we can put all the string(s) in a set or else put in vector and sort it.
    solveCasePermutes(input, output);
    
    return 0;
}