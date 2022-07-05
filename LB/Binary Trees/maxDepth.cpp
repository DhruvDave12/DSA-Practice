#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:

    void solver(TreeNode* root, int level, int &maxLevel){
        if(!root){
            if(level > maxLevel){
                maxLevel = level;
            }
            return;
        }

        solver(root->left, level+1, maxLevel);
        solver(root->right, level+1, maxLevel);
    }
    int maxDepth(TreeNode* root) {
        int level = 1;
        int maxLevel = INT_MIN;

        solver(root, level, maxLevel);
        return maxLevel;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    return 0;
}