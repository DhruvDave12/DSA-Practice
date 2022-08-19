#include <bits/stdc++.h>
using namespace std;

int findMinimumCharacters(string searchWord, string resultWord) {
    int i = 0, j = 0;
    int count = 0;

    while(i < resultWord.length() && j < searchWord.length()){
        if(resultWord[i] == searchWord[j]) {
            i++;
            j++;
            count++;
        }
        else {
            j++;
        }
    }

    return resultWord.length() - count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string searchWord = "abcz";
    string resultWord = "amzdb";

    int ans = findMinimumCharacters(searchWord, resultWord);

    cout<<"Ans: "<<ans<<"\n";
    return 0;
}