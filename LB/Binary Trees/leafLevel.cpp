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
    set<int> st;

public:
    bool check(Node *root)
    {
        if (!root)
            return true;

        queue<Node *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int len = q.size();
            level++;
            for (int i = 0; i < len; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (temp->left == NULL && temp->right == NULL)
                {
                    st.insert(level);
                }
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        if (st.size() == 1)
            return true;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}