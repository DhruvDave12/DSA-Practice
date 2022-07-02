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

class Solution {
  
  int helper1(Node* root){
        if(!root) return 0;
        
        int prev = root->data;
        root->data = helper1(root->left) + helper1(root->right);

        return prev + root->data;
  }

  public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void inorder(Node* root){
        if(!root) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void toSumTree(Node *node)
    {
        helper1(node);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    Solution s;

    s.toSumTree(root);
    return 0;
}