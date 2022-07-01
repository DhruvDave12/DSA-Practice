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

void inorderIterative(Node* root){
    if(!root) return;
    stack<Node*> st;
    // remember moving the temp ptr (curr) in this case
    Node* curr = root;
    while(!st.empty() || curr != NULL){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            curr = st.top();
            cout<<curr->data<<" ";
            st.pop();
            curr = curr->right;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    inorderIterative(root);
    return 0;
}