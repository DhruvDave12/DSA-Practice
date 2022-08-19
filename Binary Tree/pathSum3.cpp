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
    map<TreeNode*, bool> mp;

    void solver(TreeNode* root, int targetSum, vector<TreeNode*> &vec, int &counter){
        if(!root) return;
        if(!root->left && !root->right){
            vec.push_back(root);
            int sum = 0;
            for(int i=0; i<vec.size(); i++){
                if(sum+vec[i]->val <= targetSum){
                    if(mp.count(vec[i]) == 0){
                        mp[vec[i]] = true;
                        sum += vec[i]->val;
                    }                
                }
                if(sum == targetSum) {
                    counter++;
                    break;
                }
            }
        
            return;
        }

        vec.push_back(root);
        if(root->left){
            solver(root->left, targetSum, vec, counter);
            vec.pop_back();
        }
        if(root->right){
            solver(root->right, targetSum, vec, counter);
            vec.pop_back();
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<TreeNode*> vec;
        int counter = 0;
        solver(root, targetSum, vec, counter);

        return counter;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}