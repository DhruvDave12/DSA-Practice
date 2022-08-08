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
public:
    
    void fillVectorOfVector(TreeNode* root, int targetSum, vector<vector<int>> &vec, vector<int> &temp, int sum){
        if(!root) return;
        if((!root->left) && (!root->right)){
            sum += root->val;
            temp.push_back(root->val);
            if(sum == targetSum){
                vec.push_back(temp);
            } 

            return;
        }

        temp.push_back(root->val);
        if(root->left){
            fillVectorOfVector(root->left, targetSum, vec, temp, sum+root->val);
            temp.pop_back();
        }

        if(root->right){
            fillVectorOfVector(root->right, targetSum, vec, temp, sum+root->val);
            temp.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> res;
        int sum = 0;
        fillVectorOfVector(root, targetSum, res, temp, sum);

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}