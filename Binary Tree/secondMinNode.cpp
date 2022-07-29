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
    // Here the first minimum node is going to be the root node now we will traverse and tryna find one node in left or right which is greater than it
    set<int> st;
    void helper(TreeNode *root)
    {
        if (!root)
            return;

        st.insert(root->val);

        helper(root->left);
        helper(root->right);
    }

    int findSecondMinimumValue(TreeNode *root)
    {
        TreeNode *temp = root;
        helper(temp);
        if(st.size() == 1) return -1;

        set<int> :: iterator itr;
        itr++;
        return *itr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}