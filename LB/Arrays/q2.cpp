#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {5, 2, 7, 98, 189, 3};

    int maxx = vec[0];
    int minn = vec[0];

    for(int i=0; i<vec.size(); i++){
        maxx = max(maxx, vec[i]);
        minn = min(minn, vec[i]);
    }

    cout<<"MAX: "<<maxx<<"\n"<<"MIN: "<<minn<<"\n";
    return 0;
}