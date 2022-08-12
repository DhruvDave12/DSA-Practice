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
    map<int,int> mp;
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start, int end){
        if(start > end) return NULL;

        int val = postorder[postorder.size()-1];
        postorder.pop_back();
        
        TreeNode* root = new TreeNode(val);
        int idx = mp[val];

        root->right = helper(inorder, postorder, idx+1, end);
        root->left = helper(inorder, postorder, start, idx-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        int start = 0;
        int end = inorder.size()-1;

        TreeNode* res = helper(inorder, postorder, start, end);

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}