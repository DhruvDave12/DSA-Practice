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
    int helper(TreeNode* root, int &sum){
        if(!root) return  0;
        if((!root->left) && (!root->right)){
            sum += 0;
        }

        int leftSum = helper(root->left, sum);
        int rightSum = helper(root->right, sum);

        sum += leftSum+rightSum;
        return leftSum+rightSum;
    }
    int findTilt(TreeNode* root) {
        int ans = 0;
        helper(root, ans);

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}