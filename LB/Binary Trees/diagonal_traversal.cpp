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

void diagonalUtil(Node* root, map<int,vector<int>> &m, int d){
    if(!root) return;
    m[d].push_back(root->data);

    diagonalUtil(root->left,m,d+1);
    diagonalUtil(root->right, m, d);
}

void diagonalTraversal(Node* root){
    if(!root) return;
    
    map<int,vector<int>> m;
    int d = 0;
    diagonalUtil(root, m, d);

    map<int, vector<int>> :: iterator it;
    for(it = m.begin(); it!= m.end(); it++){
        vector<int> v = it->second;
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    diagonalTraversal(root);
    return 0;
}