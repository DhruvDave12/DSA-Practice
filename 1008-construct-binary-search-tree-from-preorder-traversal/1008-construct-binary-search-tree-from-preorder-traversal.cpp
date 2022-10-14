/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int getFirstGreater(vector<int> &preorder){
        for(int j=1; j<preorder.size(); j++){
            if(preorder[j] > preorder[0]) return j;
        }
        
        return preorder.size();
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        
        int maxIdx = getFirstGreater(preorder);
        TreeNode* root = new TreeNode(preorder[0]);
        
        vector<int> leftSubTree(preorder.begin()+1, preorder.begin()+maxIdx);
        vector<int> rightSubTree(preorder.begin()+maxIdx, preorder.end());
            
        root->left = bstFromPreorder(leftSubTree);
        root->right = bstFromPreorder(rightSubTree);
        
        
        return root;
    }
};