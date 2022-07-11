#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
public:
    void getCHelper(Node *root, int l, int h, int &c)
    {
        if (!root)
            return;

        if (root->data >= l && root->data <= h)
        {
            // means we have the elements in its left and right subtree also
            // cout << root->data << " ";
            c++;
            getCHelper(root->left, l, h,c);
            getCHelper(root->right, l, h,c);
        }
        if (root->data < l)
        {
            getCHelper(root->right, l, h, c);
        }
        if (root->data > h)
        {
            getCHelper(root->left, l, h, c);
        }
    }

    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        getCHelper(root, l, h, count);
        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    Solution s;
    cout<<s.getCount(root, 5, 45)<<"\n";
    return 0;
}