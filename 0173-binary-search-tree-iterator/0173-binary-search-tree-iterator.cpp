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
class BSTIterator {
    vector<int> inorder;
    
    void _fillVector(TreeNode* root){
        if(!root) return;
        _fillVector(root->left);
        inorder.push_back(root->val);
        _fillVector(root->right);
    }
    
public:
    int i = 0;
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        _fillVector(temp);    
    }
    
    int next() {
        if(i >= inorder.size()){
            return -1;
        }
        
        int ans = inorder[i];
        i++;
        return ans;
    }
    
    bool hasNext() {
        if(i < inorder.size()) return true;
        
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */