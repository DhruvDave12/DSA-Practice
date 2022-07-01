#include <bits/stdc++.h>
using namespace std;

void rearrangeArray(vector<int> &vec){
    // We can do it with extra space
    vector<int> negative;
    vector<int> positive;

    for(int i=0; i<vec.size(); i++){
        if(vec[i] >= 0){
            positive.push_back(vec[i]);
        }
        else if(vec[i] < 0){
            negative.push_back(vec[i]);
        }
    }

    int x = 0, y = 0, i = 0;
    while(x < positive.size() && y < negative.size()){
        if(i%2 == 0){
            vec[i] = negative[y];
            y++;
        }
        else if(i%2 != 0){
            vec[i] = positive[x];
            x++;
        }
        i++;
    }

    for(int j=x; j<positive.size(); j++){
        vec[i] = positive[j];
        i++;
    }

    for(int k=y; k<negative.size(); k++){
        vec[i] = negative[k];
        i++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr = {1, 2, 3, -4, -1, 4};
    rearrangeArray(arr);

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}