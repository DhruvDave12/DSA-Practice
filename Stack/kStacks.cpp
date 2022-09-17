#include <bits/stdc++.h>
using namespace std;

class kStacks {
    public:
    vector<vector<int>> vec;

    kStacks(int k){
        vector<vector<int>> vecc(k);
        this->vec = vecc;
    }

    void push(int val, int sn){
        vec[sn].push_back(val);
    }
    int pop(int sn){
        if(vec[sn].size() <= 0) return -1;
        int ele = vec[sn][vec[sn].size()-1];
        vec[sn].pop_back();
        return ele;
    }
    int size(int sn){
        return vec[sn].size();
    }

    int top(int sn){
        if(vec[sn].size() > 0){
            return vec[sn][vec[sn].size()-1];
        }
        return -1;
    }

    bool empty(int sn){
        if(vec[sn].size() == 0) return true;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    kStacks kst(5);

    kst.push(5,2);
    kst.push(4,2);
    kst.push(2,1);
    kst.push(3,3);

    cout<<kst.top(2)<<"\n";
    return 0;
}