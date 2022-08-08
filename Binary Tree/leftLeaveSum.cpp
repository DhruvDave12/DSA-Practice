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

    void helper(TreeNode* root, bool &isLeft, int &sum){
        if(!root) return;
        if((!root->left) && (!root->right) && isLeft == true){
            sum += root->val;
        }
        helper(root->left, isLeft=true, sum);
        helper(root->right, isLeft=false, sum);
        
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        bool isLeft = false;

        helper(root, isLeft, sum);
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    int ans = s.sumOfLeftLeaves(root);

    cout<<"ANS: "<<ans<<"\n";

    return 0;
}