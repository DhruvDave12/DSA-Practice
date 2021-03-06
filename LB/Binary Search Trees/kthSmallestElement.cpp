#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    void fillVector(Node *root, vector<int> &vec)
    {
        if (!root)
            return;
        fillVector(root->left, vec);
        vec.push_back(root->data);
        fillVector(root->right, vec);
    }
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K)
    {
        vector<int> inorder;
        fillVector(root, inorder);
        if(K > inorder.size()){
            return -1;
        }
        return inorder[K - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(6);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(1);
    return 0;
}