#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &vec, int temp){
    if(vec.size() == 0 || vec[vec.size()-1] <= temp){
        vec.push_back(temp);
        return;
    }
    int val = vec[vec.size()-1];
    vec.pop_back();
    insert(vec, temp);
    vec.push_back(val);
}

void sortArray(vector<int> &vec){
    if(vec.size() <= 1){
        return;
    }
    // keep removing last element this is the hypothesis
    int temp = vec[vec.size() - 1];
    vec.pop_back();
    sortArray(vec);
    insert(vec, temp);
    // Now add the removed temp element at its right place
    // so we will do that also recursively
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vec = {2,4,5,1,3,7,8};
    sortArray(vec);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}