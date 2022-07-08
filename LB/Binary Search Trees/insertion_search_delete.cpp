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

Node* insertIntoBST(Node* root, int data){
    if(!root){
        root = new Node(data);
        return root;
    }
    
    if(root->data < data){
        // we go in Right sub tree
        root->right = insertIntoBST(root->right, data);
    }
    if(root->data > data){
        // we go in Left Sub Tree
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}


bool searchINBst(Node* root, int key){
    if(!root) return false;

    if(root->data == key) return true;

    if(root->data < key){
        return searchINBst(root->right, key);
    }
    if(root->data > key){
        return searchINBst(root->left, key);
    }
}

void inorderBST(Node* root){
    if(!root) return;

    inorderBST(root->left);
    cout<<root->data<<" ";
    inorderBST(root->right);
}

Node* inorderSuccessor(Node* root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* deleteNodeBST(Node* root, int val){
    // Case 1 -> Leaf Node
    // Case 2 -> Only One Child
    // Case 3 -> Two Children
    if(!root) return root;

    if(root->data > val){
        root->left = deleteNodeBST(root->left, val);
    }
    if(root->data < val){
        root->right = deleteNodeBST(root->right, val);
    }
    if(root->data == val){
        // now we are at the node which we have to delete
        // Case 1
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        if(root->left == NULL){
            Node *returnVal = root->right;
            delete root;
            return returnVal;
        }
        if(root->right == NULL){
            Node* returnVal = root->left;
            delete root;
            return returnVal;
        }

        Node* IS = inorderSuccessor(root->right);
        root->data = IS->data;
        root->right = deleteNodeBST(root->right, IS->data);
    }
    return root;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = NULL;

    vector<int> vec = {5,1,3,4,2,7};

    /*
            5
           / \
          1  7
           \
            3
           / \
          2   4
    
    */
    for(int i=0; i<vec.size(); i++){
        root = insertIntoBST(root, vec[i]);
    }

    inorderBST(root);

    // if(searchINBst(root, 10)){
    //     cout<<"\nYES\n";
    // } else {
    //     cout<<"\nNO\n";
    // }

    cout<<"\nAFTER DELETING 3"<<"\n";
    deleteNodeBST(root, 3);
    inorderBST(root);
    return 0;
}