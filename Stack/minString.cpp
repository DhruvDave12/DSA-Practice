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
    vector<char> alphabets = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // char ch = ' '; 
    // vector<int> ans;
    string ans = "";
    int minSum (TreeNode * root){
        if(!root){
            return 0;
        }

        int x = minSum(root->left);
        int y = minSum(root->right);
        cout<<x<<" "<<y<<" "<<root->val<<"\n";
        return min(x,y) + root->val;
    }

    char smallestUtil(TreeNode *root){
        if(!root){
            return '0';
        }
        char t = smallestUtil(root->left);
        char z = smallestUtil(root->right);
        
        int x = min(t-'0', z-'0');
        ans += alphabets[x];
        ans += alphabets[root->val];
        return alphabets[x];
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root){
            return "";
        }
        char garbage = smallestUtil(root);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode*root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution s;
    string ans = s.smallestFromLeaf(root);
    // int ans = s.minSum(root);
    
    cout<<ans<<" ";
    return 0;
}