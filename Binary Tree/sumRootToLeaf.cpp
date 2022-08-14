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
    
    void fillVector(TreeNode* root, vector<int>&vec, string &s){
        if(!root){
            return;
        }
        
        if((!root->left) && (!root->right)){
            s.push_back(root->val + '0');
            int x = stoi(s);
            vec.push_back(x);
            return;
        }
        s.push_back(root->val + '0');
        if(root->left){
            fillVector(root->left, vec, s);
            s.pop_back();
        }
        if(root->right){
            fillVector(root->right, vec, s);
            s.pop_back();
        }
    }
    int sumNumbers(TreeNode* root) {
        vector<int> vec;
        string s = "";
        fillVector(root, vec, s);

        int res = 0;
        for(int i=0; i<vec.size(); i++) res += vec[i];

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}