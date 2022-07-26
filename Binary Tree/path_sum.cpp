#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public: 

    void fillVector(TreeNode* root, vector<int> &vec, int sumTillNode){
        if(!root) return;
        if((!root->left) && (!root->right)){
            sumTillNode += root->val;
            vec.push_back(sumTillNode);
            return;
        }
        fillVector(root->left, vec, sumTillNode+root->val);
        fillVector(root->right, vec, sumTillNode+root->val);
    }

    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(!root) return false;

    //     if((!root->left) && (!root->right) && (targetSum-root->val == 0)){
    //         return true;
    //     }

    //     bool left = hasPathSum(root->left, (targetSum-root->val));
    //     bool right = hasPathSum(root->right, (targetSum-root->val));

    //     return left || right;
    // }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    vector<int> vec;
    int sum = 0;

    Solution s;
    s.fillVector(root, vec, sum);

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    
    return 0;
}