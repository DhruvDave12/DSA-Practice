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
    
    int getMaxIDX(vector<int> &nums){
        int maxVal = INT_MIN;
        int maxIdx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                maxIdx = i;
            }
        }
        
        return maxIdx;
    }
    
    TreeNode* createTree(vector<int> &nums){
        if(nums.size() == 0) return NULL;
        
        int maxIdx = getMaxIDX(nums);
        
        TreeNode* root = new TreeNode(nums[maxIdx]);
        vector<int> leftSubTree(nums.begin(), nums.begin()+maxIdx);
        vector<int> rightSubTree(nums.begin()+maxIdx+1, nums.end());
        
        root->left = createTree(leftSubTree);
        root->right = createTree(rightSubTree);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // TreeNode* root = createTree(nums);
        stack<TreeNode*> st;
        
        for(auto it: nums){
            TreeNode* curr = new TreeNode(it);
            while(!st.empty() && st.top()->val < it){
                curr->left = st.top();
                st.pop();
            }
            
            // now we have the element larger than current on st.top()
            if(!st.empty()){
                st.top()->right = curr;
            }
            
            st.push(curr);
        }
        
        TreeNode* root;
        
        while(!st.empty()){
            root = st.top();
            st.pop();
        }
        return root;
    }
};