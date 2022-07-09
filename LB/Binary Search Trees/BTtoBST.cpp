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
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    vector<int> vec;

    void fillVector(Node* root){
        if(!root) return;
        fillVector(root->left);
        vec.push_back(root->data);
        fillVector(root->right);
    }

    Node* insertNode(Node* root, int data){
        if(!root){
            root = new Node(data);
            return root;
        }
        if(root->data > data){
            root->left = insertNode(root->left, data);
        }
        if(root->data < data){
            root->right = insertNode(root->right, data);
        }
        return root;
    }
    Node *binaryTreeToBST (Node *root)
    {
    //    we have to just do some changes in that same tree
    // we have to make its inorder sorted so we will swap all those nodes 
        Node* bstRoot = NULL;
        fillVector(root);

        sort(vec.begin(), vec.end());
        // now lets make the whole BST
        for(int i=0; i<vec.size(); i++){
            bstRoot = insertNode(bstRoot, vec[i]);
        }

        return bstRoot;
    }
};

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
    Node* temp = root;
    cout<<"BINARY TREE INORDER: "<<"\n";
    inorder(temp);
    cout<<"\n";
    Solution s;
    Node* bstRoot = s.binaryTreeToBST(root);

    cout<<"Corresponding BST Inorder"<<"\n";
    inorder(bstRoot);
    return 0;
}