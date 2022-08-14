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
    
    int countNodes(TreeNode *root)
    {
        if(!root) return 0;
        TreeNode* l = root->left;
        int leftLevel = 0;

        while(l){
            l = l->left;
            leftLevel++;
        }

        TreeNode* r = root->right;
        int rightLevel = 0;
        
        while(r){
            r = r->right;
            rightLevel++;
        }

        if(leftLevel == rightLevel){
            // complete tree 2^Height - 1;
            return pow(2, leftLevel) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}