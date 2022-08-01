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

void createMirror(Node* root, Node** mirror){
    if(!root) return;

    *mirror = new Node(root->data);
    createMirror(root->left, &(*mirror)->right);
    createMirror(root->right, &(*mirror)->left); 
}

bool isMirror(Node* root1, Node* root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;

    return (root1->data == root2->data) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
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

    Node* mirrorRoot; 
    Node* temp = root;
    createMirror(root, &mirrorRoot);
    Node* temp2 = mirrorRoot;

    cout<<"INORDERS: "<<"\n";
    inorder(temp);
    cout<<"\n";
    inorder(temp2);

    if(isMirror(root, mirrorRoot)){
        cout<<"\nYES"<<"\n";
    }
    else {
        cout<<"\nNO"<<"\n";
    }
    return 0;
}