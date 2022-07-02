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

class Solution
{
    vector<pair<int,int>> vec;

    int helper(Node* root){
        if(!root) return 0;

        int originalVal = root->data;
        int newVal = helper(root->left) + helper(root->right);

        if(!(root->left == NULL && root->right == NULL)){
            vec.push_back({originalVal, newVal});
        }   
        return originalVal + newVal;
    }

    public:
    bool isSumTree(Node* root)
    {
        helper(root);

        vector<pair<int,int>> :: iterator itr;

        for(itr = vec.begin(); itr != vec.end(); itr++){
            if(itr->first != itr->second){
                return false;
            }
            // cout<<itr->first<<" "<<itr->second<<"\n";
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(10);
    root->left->right = new Node(10);
    // root->right->left = new Node(7);
    // root->right->right = new Node(5);

    Solution s;

    s.isSumTree(root);

    return 0;
}