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

class Solution
{
public:

    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if(!root) return root;
        queue<TreeNode*> q;
        vector<int> vals;
        vector<int> vec;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            vec.clear();
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(level % 2 != 0){
                    temp->val = vals[size-i-1];
                }

                if(temp->left){
                    q.push(temp->left);
                    vec.push_back(temp->left->val);
                }
                if(temp->right){
                    q.push(temp->right);
                    vec.push_back(temp->right->val);
                }
            }
            vals = vec;
            level++;
        }

        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}