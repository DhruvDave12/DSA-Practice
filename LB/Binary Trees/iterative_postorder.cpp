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

void iterativePostorder(Node* root){
    if(!root) return;

    stack<Node*> st;
    stack<Node*> out;
    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        out.push(temp);
        if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
    }

    while(!out.empty()){
        cout<<out.top()->data<<" ";
        out.pop();
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

    iterativePostorder(root);
    return 0;
}