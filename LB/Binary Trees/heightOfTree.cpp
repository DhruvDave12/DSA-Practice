#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

int heightOfTree(Node* root){
    // we calculate the max of left and right subtree recursively and return max(L,R)+1
    if(root == NULL){
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return 1+max(leftHeight, rightHeight);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}