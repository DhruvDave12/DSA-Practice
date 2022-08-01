#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void constructTree(TreeNode *root, TreeNode **res)
    {
        if (!root) return;
        constructTree(root->left, &(*res));
        *res = new TreeNode(root->val);
        res = &(*res)->right;
        constructTree(root->right, &(*res));
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *res;
        constructTree(root, &res);
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}