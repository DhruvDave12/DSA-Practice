#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
    // TreeNode* solver(vector<int>&nums, int start, int end, int mid, TreeNode* &root){
    //     if(start > end) return NULL;
        
    //     root = new TreeNode(nums[mid]); 
    //     int newMid = start + (end-start)/2;
    //     root->left = solver(nums, start, mid-1, newMid, root->left);
    //     root->right = solver(nums, mid+1, end, newMid, root->right);

    //     return root;
    // }
     
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return NULL;
        if (len == 1) return new TreeNode(nums[0]);

        int mid = len / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> leftV(nums.begin(), nums.begin()+mid);
        vector<int> rightV(nums.begin()+mid+1, nums.end());

        root->left = sortedArrayToBST(leftV);
        root->right = sortedArrayToBST(rightV);

        return root;

        // TreeNode* root = NULL;
        // TreeNode* root2 = solver(nums,0,nums.size()-1, nums.size()/2, root);
        // return root2;
    }
    // void inorder(TreeNode* root){
    //     if(!root) return;
    //     inorder(root->left);
    //     cout<<root->data<<" ";
    //     inorder(root->right);
    // }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution s;
    TreeNode* root = s.sortedArrayToBST(nums);

    return 0;
}