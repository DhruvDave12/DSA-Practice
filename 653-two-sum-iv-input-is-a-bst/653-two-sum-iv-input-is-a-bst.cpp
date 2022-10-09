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
    TreeNode* initNode;
    
    bool search(TreeNode* root, int key, TreeNode* ogNode){
        if(!root) return false;
        
        
        if(key == root->val && root != ogNode) {
            return true;
        };
        
        if(key < root->val) {
            return search(root->left, key, ogNode);
        }
        else {
            
            return search(root->right, key, ogNode);
        }
    }
    
    bool helper(TreeNode* root, int k){
        if(!root) return false;
        
        int currVal = root->val;
        TreeNode* temp = root;
        TreeNode* initCopy = initNode;
        
        bool searchOtherHalve = search(initCopy,k-currVal,temp);
        
        
        if(searchOtherHalve) return true;
        
        return helper(root->left,k) || helper(root->right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        this->initNode = root;
        return helper(root,k);
    }
};