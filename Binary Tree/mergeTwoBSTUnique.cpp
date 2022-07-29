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


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) return NULL;

        TreeNode* root = new TreeNode();
        if(root1){
            root->val += root1->val;
        }
        if(root2){
            root->val += root2->val;
        }

        root->left = mergeTrees(root1?root1->left : NULL, root2?root2->left:NULL);
        root->right = mergeTrees(root1?root1->right:NULL,root2?root2->right:NULL);

        return root;
    }
};

void inorder(TreeNode* res){
    if(!res) return;
    inorder(res->left);
    cout<<res->val<<" ";
    inorder(res->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    Solution s;
    TreeNode* ans = s.mergeTrees(root1,root2);
    inorder(ans);
    return 0;
}