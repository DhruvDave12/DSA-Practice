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

class Solution
{
    public: 
    Node* DLL = NULL;
    Node* temp = DLL;
    vector<Node*> vec;
    //Function to convert binary tree to doubly linked list and return it.
    void insertIntoDLL(){
        for(int i=0; i<vec.size(); i++){
            if(DLL == NULL){
                DLL = vec[i];
                temp = DLL;
            }
            else{
                temp->right = vec[i];
                vec[i]->left = temp;
                temp = vec[i];
            }
        }
    }

    void helperFunction(Node* root){
        if(!root) return;

        helperFunction(root->left);
        // cout<<root->data<<" ";
        vec.push_back(root);
        helperFunction(root->right);
    }

    Node * bToDLL(Node *root)
    {   
        if(!root) return DLL;
        helperFunction(root);
        insertIntoDLL();
        return DLL;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Solution s;
    s.bToDLL(root);
    return 0;
}