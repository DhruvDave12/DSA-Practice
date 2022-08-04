#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        while((p%2==0) && (q%2==0)){
            p /=2;
            q /=2;
        }

        if(p%2 == 0) return 2;

        if(q%2 == 0) return 0;

        return 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    return 0;
}