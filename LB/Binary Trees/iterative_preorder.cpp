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

// maintain the required order inside the stack and thats the key for such problems
void iterativePreorder(Node* root){
    if(!root) return;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* temp = st.top();
        if(temp){
            cout<<temp->data<<" ";
        }
        st.pop();
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
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

    iterativePreorder(root);
    return 0;
}