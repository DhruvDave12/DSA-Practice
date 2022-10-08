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
    void solver(TreeNode *root, int val, int currD, int reqD, bool isLeft)
    {
        if (!root)
            return;

        if (currD == reqD - 1)
        {
            // do the adding node operation here
            TreeNode *toAddL = new TreeNode(val);
            TreeNode *toAddR = new TreeNode(val);

            TreeNode *ogLeft = root->left;
            TreeNode *ogRight = root->right;

            toAddL->left = ogLeft;
            toAddR->right = ogRight;

            root->left = toAddL;
            root->right = toAddR;
        }
        solver(root->left, val, currD + 1, reqD, isLeft = true);
        solver(root->right, val, currD + 1, reqD, isLeft = false);
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        solver(root, val, 1, depth, false);
        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
