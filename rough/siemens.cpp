#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool getPath(node *root, int n1, vector<node*> path)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == n1)
    {
        return true;
    }

    path.push_back(root);
    if (getPath(root->left, n1, path) || getPath(root->right, n1, path))
    {
        return true;
    }

    path.pop_back();

    return false;
}

node* LCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return root;
    }

    vector<node*> v1, v2;

    if (!getPath(root, n1, v1) || !getPath(root, n2, v2))
    {
        return NULL;
    }

    int i;
    for (i = 0; i < v1.size() && v2.size(); i++)
    {
        if (v1[i]->data != v2[i]->data)
        {
            break;
        }
    }
    return v1[i - 1];
}

int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
    root->right->left = new node(5);
    root->right->left->left = new node(7);
    root->right->right = new node(6);

    return 0;
}