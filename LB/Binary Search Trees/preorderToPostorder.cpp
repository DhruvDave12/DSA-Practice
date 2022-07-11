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
    
    Node* buildTree(int pre[], int n, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        Node* root = new Node(pre[mid]);
        root->left = buildTree(pre, n, start, mid-1);
        root->right = buildTree(pre, n, mid+1, end);
        return root;
    }
    
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        int preIdx = 0;
        Node* root = NULL;
        sort(pre, pre+size);
        root = buildTree(pre,size,0,size-1);
        return root;
    }

    void postorder(Node* root){
        if(!root) return;

        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int pre[] = {40, 30, 35, 80, 100};
    int size = 5;

    Solution s;
    Node* root = s.post_order(pre, size);
    
    s.postorder(root);
    return 0;
}