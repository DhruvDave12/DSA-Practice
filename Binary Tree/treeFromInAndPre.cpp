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
    map<int,int> mp;
    int preIdx = 0;
public:

    TreeNode* helper(vector<int>&preorder, vector<int>&inorder, int start, int end){
        if(start > end) return NULL;
        int val = preorder[preIdx];
        preIdx++;

        TreeNode* root = new TreeNode(val);

        int idx = mp[val];

        root->left = helper(preorder, inorder, start, idx-1);
        root->right = helper(preorder, inorder, idx+1, end);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {   
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = helper(preorder, inorder, 0, preorder.size()-1);

        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}