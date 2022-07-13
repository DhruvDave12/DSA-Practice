#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void helper(Node* root, map<int,bool> &mp, vector<int> &v){
    if(!root) return;
    helper(root->left,mp, v);
    mp[root->data] = true;
    if(!root->left && !root->right) v.push_back(root->data);
    helper(root->right,mp,v);
}

bool isDeadEnd(Node *root)
{
    vector<int> vec;
    map<int,bool> mp;
    Node* temp = root;
    helper(temp, mp, vec); 

    for(int i=0; i<vec.size(); i++){
        if(vec[i] == 1 && mp.count(vec[i]+1) != 0) return true;
        if(mp.count(vec[i]+1) != 0 && mp.count(vec[i]-1) != 0) return true;
    }   
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}