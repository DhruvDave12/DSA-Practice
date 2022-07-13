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

class NodeMetaData {
    public:
    int maxNode;
    int minNode;
    int maxSize;

    NodeMetaData(int maxx, int minn, int maxxSize){
        this->maxNode = maxx;
        this->minNode = minn;
        this->maxSize = maxxSize;
    }
};

class Solution {
    public:

    NodeMetaData* largestBSTSize(Node* root){
        if(!root) return new NodeMetaData(INT_MIN, INT_MAX, 0);

        NodeMetaData* leftt = largestBSTSize(root->left);
        NodeMetaData* rightt = largestBSTSize(root->right);
        
        if(leftt->maxNode < root->data && rightt->minNode > root->data){
        // here we mean it is a bst
            return new NodeMetaData(max(root->data, rightt->maxNode), min(root->data, leftt->minNode), 1+leftt->maxSize + rightt->maxSize);
        }
        // violates BST Conditions
        return new NodeMetaData(INT_MAX, INT_MIN, max(leftt->maxSize, rightt->maxSize));
    }

};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    Solution s;
    cout<<s.largestBSTSize(root)->maxSize<<"\n";
    return 0;
}