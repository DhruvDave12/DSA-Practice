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

class Solution {
    public:
    int maxSumNotAdjacent(Node* node, map<Node*, int> &mp){
        if(!node) return 0;

        if(mp.count(node) != 0){
            // we find that node in map so
            return mp[node];
        }

        int includingCurrentNode = node->data + grandChildrenSum(node, mp);
        int excludingCurrentNode = maxSumNotAdjacent(node->left, mp) + maxSumNotAdjacent(node->right, mp);

        mp[node] = max(includingCurrentNode, excludingCurrentNode);

        return mp[node];
    }

    int grandChildrenSum(Node* node, map<Node*, int> &mp){
        int sum = 0;
        if(node->left){
            sum += maxSumNotAdjacent(node->left->left, mp) + maxSumNotAdjacent(node->left->right, mp);
        }

        if(node->right){
            sum += maxSumNotAdjacent(node->right->left, mp) + maxSumNotAdjacent(node->right->right, mp);
        }

        return sum;
    }


    

    int maxUtill(Node* node){
        if(!node) return 0;
        map<Node*, int> mp;
        return maxSumNotAdjacent(node, mp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);

    Solution s;
    int ans = s.maxUtill(root);

    cout<<"ANS: "<<ans<<"\n";
    return 0;
}