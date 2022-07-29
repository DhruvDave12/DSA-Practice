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


// VIMP -> Trick is to simply just call recursion just as we need the tree check code for more clarity....
class Solution {
public:
// traverse preorder when going then add number and opening bracket in the string and when return add closing bracket
    string tree2str(TreeNode* root) {
        if(!root) return "";

        if(!root->left && !root->right){
            return to_string(root->val);
        }

        if(!root->right){
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }

        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}