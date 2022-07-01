#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(Node* root){
    if (!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1+max(leftHeight, rightHeight);
}

int diameter(Node* root){
    // here two cases arise one length through the root and one not
    // lets code
    if(!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int leftDiam = diameter(root->left);
    int rightDiam = diameter(root->right);
    return max(1+leftHeight+rightHeight, max(leftDiam, rightDiam));
}

int easyDiameter(Node* root, int& ans){
    if(!root) return 0;

    int lh = easyDiameter(root->left, ans);
    int rh = easyDiameter(root->right, ans);
    ans = max(ans, 1+lh+rh);
    return 1 + max(lh , rh);
}

int diameterFinal(Node* root){
    if(!root) return 0;
    int ans = INT_MIN;
    easyDiameter(root, ans);
    return ans;
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

    int ans = diameter(root);
    cout<<"ANS: "<<ans<<"\n";

    int anss = diameterFinal(root);
    cout<<"O(N) ANSWER: "<<anss<<"\n";
    return 0;
}