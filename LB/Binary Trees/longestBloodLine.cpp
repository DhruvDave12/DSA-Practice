#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
 public:
    void solver(Node* root, int sum, int len, int& maxLen, int& maxSum){
        if(!root){
            if(maxLen < len){
                maxLen = len;
                maxSum = sum;
            }
            if(maxLen == len && maxSum < sum){
                maxSum = sum;
            }

            return;
        }

        solver(root->left, sum+root->data, len+1, maxLen, maxSum);
        solver(root->right, sum+root->data, len+1, maxLen, maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum = 0, maxSum = 0, len = 0, maxLen = 0;
        solver(root, sum, len, maxLen, maxSum);

        return maxSum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
 
    Solution s;
    cout<<s.sumOfLongRootToLeafPath(root)<<"\n";
    return 0;
}