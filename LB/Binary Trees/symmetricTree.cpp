#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if((!p || !q) || (p->val != q->val)) return p==q;

        return isSame(p->left, q->right) && isSame(p->right, q->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return isSame(root, root);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    // root->right->right->left = new TreeNode(8);

    Solution s;
    if(s.isSymmetric(root)){
        cout<<"YES"<<"\n";
    } else {
        cout<<"NO"<<"\n";
    }
    return 0;
}