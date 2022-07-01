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

void mirrorConverter(Node* root, Node** mirror){
    if(!root){
        mirror = NULL;
        return;
    }
    *mirror = new Node(root->data);
    // when we go to the left of root we need to point towards the right of mirror and then we create a new node there....
    mirrorConverter(root->left, &(*mirror)->right);
    // when we go to the right of root we need to point towards the left of mirror and then we create a new node there....
    mirrorConverter(root->right, &(*mirror)->left);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout<<"BEFORE: "<<"\n";
    inorder(root);
    cout<<"\n";
    Node* mirror =  NULL;
    cout<<"\n";

    mirrorConverter(root, &mirror);
    
    cout<<"AFTER: "<<"\n";
    inorder(mirror);

    return 0;
}