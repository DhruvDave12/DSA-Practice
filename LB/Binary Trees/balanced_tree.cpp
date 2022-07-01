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

class Solution{
    int currentLeft = 0;
    int currentRight = 0;

    int height(Node* root){
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        // cout<<"LEFT HEIGHT: "<<lh<<" "<<"RIGHT HEIGHT: "<<rh<<"\n";
        if(abs(rh-lh) > 1){
            // means tree aint balanced
            return -1e5;
        }
        return 1 + max(lh,rh);
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(!root) return true;
        
        int val = height(root);
        if(val < 0) return false;
        return true;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}