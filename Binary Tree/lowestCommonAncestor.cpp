#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void fillVector(TreeNode* root, int X, vector<TreeNode*> &vec){
        if(!root) return;
        if(root->val == X){
            return;
        }

        if(root->val > X){
            vec.push_back(root);
            fillVector(root->left, X, vec);
        }
        if(root->val < X){
            vec.push_back(root);
            fillVector(root->right, X, vec);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>vec1, vec2;
        TreeNode* temp1 = root, *temp2 = root;
        fillVector(temp1, p->val, vec1);
        fillVector(temp2, q->val, vec2);
        
        int i;
        TreeNode* ans;

        for(i=0; i<vec1.size() && vec2.size(); i++){
            if(vec1[i] == vec2[i]){
                ans = vec1[i];
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}