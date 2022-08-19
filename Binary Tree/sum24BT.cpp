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
    map<int, int> mp;
    void fillMap(TreeNode *root, int i)
    {
        if (!root)
            return;

        fillMap(root->left, i+1);
        mp[root->val] = i;
        fillMap(root->right, i+1);
    }

    bool findTarget(TreeNode *root, int k)
    {
        fillMap(root, 0);

        map<int, int>::iterator itr;

        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            int toGet = k - itr->first;
            int checker = itr->second;

            if(mp.count(toGet) != 0){
                if(mp[toGet] != checker) return true;
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}