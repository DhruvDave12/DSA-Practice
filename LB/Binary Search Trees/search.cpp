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

bool search(Node* root, int key){
    if(!root) return false;
    if(root->data==key) return true;

    if(root->data < key){
        return search(root->right, key);
    }
    if(root->data > key){
        return search(root->left, key);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}