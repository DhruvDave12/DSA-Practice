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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    void fillVector(Node* root, vector<int> &vec){
        if(!root) return;
        fillVector(root->left, vec);
        vec.push_back(root->data);
        fillVector(root->right, vec);
    }

    public:
    int kthLargest(Node *root, int K)
    {
        vector<int> inorder;
        fillVector(root, inorder);
        return inorder[K-1];    
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}