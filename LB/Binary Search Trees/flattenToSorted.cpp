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
    public:
    void fillVector(Node* root, vector<Node*> &vec){
        if(!root) return;
        fillVector(root->left,vec);
        vec.push_back(root);
        fillVector(root->right,vec);
    }

    void makeList(Node** root, vector<Node*> vec, int &i){
        if(i == vec.size()) return;
        *root = new Node(vec[i]->data);
        i++;
        makeList(&(*root)->right, vec, i);
    }
    // assuming the root is of a BST
    Node* flattenToList(Node* root){
        vector<Node*> vec;
        fillVector(root, vec);
        Node* res = NULL;
        int i = 0;
        makeList(&res, vec, i);
        return res;
    }

    void inorder(Node* root){
        while(root){
            cout<<root->data<<" ";
            root = root->right;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);

    Solution S;
    Node* res = S.flattenToList(root);
    S.inorder(res);
    return 0;
}