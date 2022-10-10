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
    
    void fillVector(TreeNode* root, vector<int> &vec){
        if(!root) return;
        
        fillVector(root->left,vec);
        vec.push_back(root->val);
        fillVector(root->right, vec);
    }
    
    TreeNode* createRequirements(vector<int> vec){
        TreeNode* rootNode = new TreeNode(-11);
        TreeNode* temp = rootNode;
        for(int i=0; i<vec.size(); i++){
            temp->right = new TreeNode(vec[i]);
            temp = temp->right;   
        }
        
        return rootNode->right;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> vec;
        
        TreeNode* temp = root;
        fillVector(temp,vec);
        
        TreeNode* ans = createRequirements(vec);
        
        return ans;
    
    }
};