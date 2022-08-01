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
    TreeNode* parent = NULL;
    void fillMap(TreeNode *root, map<int, pair<int,int>> &mp, int d, TreeNode* parent)
    {
        if (!root)
            return;
    
        mp[root->val] = make_pair(parent->val, d);
        fillMap(root->left, mp, d + 1, root);
        fillMap(root->right, mp, d + 1, root);
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        map<int, pair<int,int>> mp;
        int d = 0;
        TreeNode* parent = new TreeNode(-1);
        fillMap(root, mp, d, parent);

        map<int,pair<int,int>> :: iterator it;
        for(it=mp.begin(); it != mp.end(); it++){
            cout<<it->first<<" -> { "<<it->second.first<<", "<<it->second.second<<" }\n";
        }

        if (mp[x].second == mp[y].second && mp[x].first != mp[y].first)
            return true;

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    Solution s;
    bool ans = s.isCousins(root, 2, 3);
    if(ans){
        cout<<"YES"<<"\n";
    } else {
        cout<<"NO"<<"\n";
    }
    return 0;
}