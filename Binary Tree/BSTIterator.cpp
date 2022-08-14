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

class BSTIterator
{
TreeNode* rootInst;
vector<int> inorder;
int i = 0;
void fillVec(TreeNode* root){
    if(!root) return;

    fillVec(root->left);
    inorder.push_back(root->val);
    fillVec(root->right);
}
public:

    BSTIterator(TreeNode *root)
    {
        this->rootInst = root;
        fillVec(this->rootInst);
    }

    int next()
    {
        if(i < inorder.size()){
            return inorder[i++];
        }

        return -1;
    }

    bool hasNext()
    {
        if(i < inorder.size()) return true;

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}