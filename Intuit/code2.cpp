#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int solver(vector<int> v1, int X, int Y){
    vector<int> preFix;
    int sum=0;
    int ans = 0;
    for(int i=0; i<v1.size(); i++){
        sum += v1[i];
        preFix.push_back(sum);
    }
    int x,y;
    for(int i=0; i<preFix.size(); i++){
        if(preFix[i]>0){
            y = preFix[i];
            x = (i+1)-preFix[i];
            if(x >= X && y >= Y) {
                // cout<<"XD: "<<x<<" "<<y<<"\n";
                int one = x / X;
                int two = y / Y;
                ans = ans + min(one,two);
                ans = ans % MOD;
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++) cin>>vec[i] ;

    int X,Y;cin>>X>>Y;

    int ans = solver(vec,X,Y);

    cout<<ans<<"\n";
  
    return 0;
}