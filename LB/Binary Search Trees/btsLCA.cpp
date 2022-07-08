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

//Function to find the lowest common ancestor in a BST. 
bool fillVector(Node* root, int key, vector<Node*> &vec){
    if(!root) return false;
    if(root->data > key){
        vec.push_back(root);
        return fillVector(root->left, key, vec);
    }
    if(root->data < key){
        vec.push_back(root);
        return fillVector(root->right, key, vec);
    }

    if(root->data == key){
        return true;
    }
}

Node* LCA(Node *root, int n1, int n2)
{
    vector<Node*> vec1, vec2;
    Node* temp1 = root, *temp2 = root;
    bool found1 = fillVector(temp1, n1, vec1);
    bool found2 = fillVector(temp2, n2, vec2);
    int count = 0;
    Node* res = NULL;
    
    for(int i=0;i<vec2.size(); i++){
        if(vec2[i]->data == n1){
            return vec2[i];
        }
    }
    
    for(int i=0; i<vec1.size(); i++){
        if(vec1[i]->data == n2){
            return vec1[i];
        }
    }
    
    for(int i=0; i<vec1.size() && i<vec2.size(); i++){
        if(vec1[i] == vec2[i]){
            count++;
            res = vec1[i];
        } else {
            break;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    return 0;
}