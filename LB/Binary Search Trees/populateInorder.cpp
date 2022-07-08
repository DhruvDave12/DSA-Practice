#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

class Solution
{
public:
    map<Node*, Node*> inorderSucMap;
    Node* prev = NULL;

    void fillMap(Node* root){
        if(!root) {
            inorderSucMap[prev] = new Node(-1);
            return;
        }

        fillMap(root->left);
        if(prev){
            inorderSucMap[prev] = root;
        }
        prev = root;
        fillMap(root->right);
    }

    void attachPointers(Node* root){
        if(!root) return;
        attachPointers(root->left);
        root->next = inorderSucMap[root];
        attachPointers(root->right);
    }

    void populateNext(Node *root)
    {   
        Node* temp = root;
        fillMap(root);
        attachPointers(temp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);


    Solution s;
    s.populateNext(root);

    cout<<root->next->data<<"\n";
    cout<<root->left->next->data<<"\n";
    cout<<root->right->next->data<<"\n";

    return 0;
}