#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int x){
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertLevelOrder(vector<int> nodes, int i){
    Node* root = NULL;
    if(i<nodes.size()){
        Node* newNode = new Node(nodes[i]);
        root = newNode;

        root->left = insertLevelOrder(nodes, 2*i + 1);
        root->right = insertLevelOrder(nodes, 2*i + 2);
    }
    return root;
}

// Inorder
void printTreeDFS(Node* root){
    if(root == NULL){
        return;
    }
    printTreeDFS(root->left);
    cout<<root->val<<" ";
    printTreeDFS(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    } 

    Node* root = insertLevelOrder(vec, 0);
    printTreeDFS(root);
    return 0;
}