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
    TreeNode* getLCA(TreeNode* root, TreeNode*p, TreeNode* q, bool &v1, bool &v2){
        if(!root) return root;

        if(root->val == p->val) {
            v1 = true;
            return root;
        }

        if(root->val == q->val){
            v2 = true;
            return root;
        }

        TreeNode* leftLCA = getLCA(root->left, p, q, v1, v2);
        TreeNode* rightLCA = getLCA(root->right, p, q, v1, v2);

        if(leftLCA && rightLCA) return root;

        return leftLCA ? leftLCA : rightLCA;
    }

    bool findNode(TreeNode* root, TreeNode* key){
        if(!root) return false;
        if(root->val == key->val) return true;

        bool inLeft = findNode(root->left, key);
        bool inRight = findNode(root->right, key);

        if(inLeft || inRight) return true;
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool v1 = false, v2 = false;

        TreeNode* lca = getLCA(root, p, q, v1, v2);
        TreeNode* temp1 = root, *temp2 = root;

        if((v1&&v2) || (v1 && findNode(temp1, q)) || (v2 && findNode(temp2, p))){
            return lca;
        }

        return NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}