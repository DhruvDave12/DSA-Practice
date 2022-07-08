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

void findPre(Node* root, int key, Node* &pre){
    if(!root) return;
    
    if(root->data < key){
        pre = root;
        findPre(root->right, key, pre);
    }
    else findPre(root->left, key, pre);
}

void findSuc(Node*root, int key, Node* &suc){
    if(!root) return;
    if(root->data > key){
        suc = root;
        findSuc(root->left, key, suc);
    }    
    else findSuc(root->right, key, suc);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    findPre(root,key,pre);
    findSuc(root,key,suc);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}