#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->right = NULL;
        this->left = NULL;
        this->val = data;
    }
};
void getLeftMostLeaf(TreeNode* root, bool &isLeft, int &ans){
    if(!root) return;

    if(isLeft && (!root->left) && (!root->right)){
        ans += root->val;
    }
    getLeftMostLeaf(root->left, isLeft=true, ans);
    getLeftMostLeaf(root->right, isLeft=false, ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int ans = 0;
    bool isLeft = false;
    getLeftMostLeaf(root, isLeft, ans);

    cout<<ans<<"\n";

    return 0;
}