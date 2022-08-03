#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode *list;
    int getLen(ListNode *head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    TreeNode *createTree(int n)
    {
        if (n == 0)
            return NULL;

        TreeNode *root = new TreeNode();
        root->left = createTree(n / 2);
        root->val = list->val;
        list = list->next;
        root->right = createTree(n - n / 2 - 1);
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        list = head;
        ListNode *temp = head;
        int N = getLen(temp);

        TreeNode* root = createTree(N);
        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}