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

class myDS {
    public:
    int key;
    vector<int> vec;
};

class Solution {
public:

    void fillMyDs(TreeNode* root, vector<myDS> &vec, int sum, myDS curr, vector<int> &vecc){
        if(!root) return;
        if((!root->left) && (!root->right)){
            sum += root->val;
            vecc.push_back(root->val);
            curr.key = sum;
            curr.vec = vecc;
            vec.push_back(curr);
            curr.key = -1;
            curr.vec.clear();
            return;
        }
        vecc.push_back(root->val);
        fillMyDs(root->left, vec, sum+root->val, curr, vecc);
        vecc.pop_back();
        fillMyDs(root->right, vec, sum+root->val, curr, vecc);
        vecc.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;

        vector<myDS> vec1;
        vector<int> vec2;
        int sum = 0;
        myDS curr;
        fillMyDs(root, vec1,sum,curr,vec2);

        for(int i=0; i<vec1.size(); i++){
            if(vec1[i].key == targetSum){
                res.push_back(vec1[i].vec);
            }
        }

        return res;
    }
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
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;
    vector<vector<int>> ans = s.pathSum(root, 22);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}