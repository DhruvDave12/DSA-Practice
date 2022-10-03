#include <bits/stdc++.h>
using namespace std;

class Force {
    public:
    int magnitude;
    int direction;
};

class Solution {
public:
    
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        vector<Force> vec(N);
        int flag = -1;
        // handling the right side pushes
        for(int i=0; i<N; i++){
            if(dominoes[i] == 'R') flag = i;
            if(dominoes[i] == 'L') flag = -1;
            if(dominoes[i] == '.'){
                if(flag != -1){
                    int mag = i-flag;
                    vec[i].direction = 1;
                    vec[i].magnitude = mag;
                }
            }
        }    

        flag = -1;
        
        // handling left pushes
        for(int i=N-1; i >= 0; i--){
            if(dominoes[i] == 'L') flag = i;
            if(dominoes[i] == 'R') flag = -1;
            if(dominoes[i] == '.'){
                if(flag != -1){
                    if(vec[i].direction == 0) dominoes[i] = 'L';
                    else{
                        int leftMag = flag-i;
                        int rightMag = vec[i].magnitude;
                        if(leftMag < rightMag) dominoes[i] = 'L';
                        else if(rightMag < leftMag) dominoes[i] = 'R';
                    }
                } else if(vec[i].direction == 1) {
                    dominoes[i] = 'R';
                }
            }
        }

        return dominoes;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}