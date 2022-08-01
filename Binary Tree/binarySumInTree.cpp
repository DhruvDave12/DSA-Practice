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
    
    void fillVector(TreeNode* root, string &s, vector<string> &vec){
        if(!root){
            return;
        }
        if((!root->left) && (!root->right)){
            s.push_back(root->val + '0');
            vec.push_back(s);
            return;
        }

        s.push_back(root->val + '0');
        if(root->left){
            fillVector(root->left, s, vec);
            s.pop_back();
        }
        if(root->right){
            fillVector(root->right, s, vec);
            s.pop_back();
        }
    }

    long long getDecimal(string binary){
        long long x = 0;
        long long  res = 0;

        for(int i=binary.length()-1; i>=0; i--){
            int z = binary[i] - '0';
            res = res + (z * (pow(2, x)));
            x++;
        }
        return res;
    }

    int sumRootToLeaf(TreeNode *root)
    {
        vector<string> vec;
        string s = "";
        fillVector(root, s, vec);

        // now convert these binary strings to decimal and add them simply and then return the sum ....
        int ans = 0;
        for(int i=0; i<vec.size(); i++){
            int ress = getDecimal(vec[i]);
            ans += ress;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    Solution s;

    s.sumRootToLeaf(root);


    return 0;
}