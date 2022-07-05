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
    int helper(Node *root, int &ans)
    {
        if (!root)
        {
            return 0;
        }
        int leftSub = helper(root->left, ans);
        int rightSub = helper(root->right, ans);

        ans = max(ans, leftSub + rightSub + root->data);
        return root->data + leftSub + rightSub;
    }

public:
    int maxSumSubTree(Node* root){
        int ans = INT_MIN;
        int hehe = helper(root, ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* root2 = new Node(1);
    root2->left = new Node(-2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(-6);
    root2->right->right = new Node(2);

    Solution s;
    int ans = s.maxSumSubTree(root);
    int ans2 = s.maxSumSubTree(root2);

    cout<<"TREE 1 MAX SUM: "<<ans<<"\n";
    cout<<"TREE 2 MAX SUM: "<<ans2<<"\n";

    return 0;
}