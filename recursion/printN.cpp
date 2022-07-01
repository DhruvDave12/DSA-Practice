#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void print(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    print(n-1);
    cout<<n<<" ";
}

void printBack(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    printBack(n-1);
}

int printFactorial(int n){
    if(n==1){
        return 1;
    }

    return n*printFactorial(n-1);
}

int getTreeHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSubTree = getTreeHeight(root->left);
    int rightSubTree = getTreeHeight(root->right);

    return 1 + max(leftSubTree, rightSubTree);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    print(10);
    cout<<"\n";
    printBack(10);
    cout<<"\n";
    cout<<printFactorial(5);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout<<"\n";
    cout<<getTreeHeight(root);
    return 0;
}