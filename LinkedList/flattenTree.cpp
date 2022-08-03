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
    
    void fillVector(TreeNode* root, vector<int> &vec){
        if(!root) return;

        fillVector(root->left, vec);
        vec.push_back(root->val);
        fillVector(root->right, vec);
    }
    
    void attachPointers(TreeNode**root, vector<int> vec, int i){
        if(i == vec.size()){
            return;
        }

        if(*root){
            (*root)->val = vec[i];
        }
        else {
            *root = new TreeNode(vec[i]);
        }
        (*root)->left = NULL;
        attachPointers(&(*root)->right, vec, i+1);
    }

    void flatten(TreeNode* root) {
        vector<int> vec;
        TreeNode* temp = root, *temp2 = root;
        fillVector(temp, vec);
        sort(vec.begin(), vec.end());

        attachPointers(&temp2, vec, 0);
    }
};

void inorder(TreeNode* root){
    if(!root) return;
    TreeNode* temp = root;

    while(temp){
        cout<<temp->val<<" ";
        temp = temp->right;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution s;
    s.flatten(root);
    inorder(root);
    return 0;
}