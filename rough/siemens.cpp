#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;

    string s = to_string(n);
    string sol;

    for(int i = 0; i < k; i++)
    {
        sol += s[i];
    }

    int count = 0;
    // cout<<sol<<endl;
    
    if(n % stoi(sol) == 0)
    {
        count++;
    }

    for(int i = k; i < s.size(); i++)
    {
        sol = sol.erase(0, 1);
        // sol += s[i];
        sol += s[i];
        // cout<<sol<<endl;
        if(stoi(sol) == 0){
            continue;
        }
        if(n % stoi(sol) == 0)
        {
            count++;
        }
    }

    cout<<"Count "<<count<<endl;

    return 0;
}