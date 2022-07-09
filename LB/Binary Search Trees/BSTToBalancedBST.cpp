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

void fillVector(Node*root, vector<int> &vec){
    if(!root) return;
    fillVector(root->left, vec);
    vec.push_back(root->data);
    fillVector(root->right, vec);
}

Node* insertNode(vector<int> &vec, int start, int end){
   if(start > end) return NULL;
    Node* root;
    int mid = (start + end) / 2;
    root = new Node(vec[mid]);
    root->left = insertNode(vec, start, mid);
    root->right = insertNode(vec, mid+1, end);
}

Node* buildBalancedTree(Node* root)
{
	vector<int> inorder;
    fillVector(root, inorder);
    Node* balancedRoot = insertNode(inorder,0, inorder.size()-1);
    return balancedRoot;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}