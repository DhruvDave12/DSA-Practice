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
    void fillVector(Node* root, vector<int> &vec){
        if(!root) return;

        fillVector(root->left, vec);
        vec.push_back(root->data);
        fillVector(root->right, vec);
    }

    Node* balanceAddToOtherTree(vector<int> &vec, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        Node* root = new Node(vec[mid]);
        root->left = balanceAddToOtherTree(vec, start, mid-1);
        root->right = balanceAddToOtherTree(vec, mid+1, end);
        return root;
    }

    Node* mergeTwoBalancedBST(Node* root1, Node* root2){
        vector<int> vec1, vec2;
        Node* temp1 = root1, *temp2 = root2;
        fillVector(temp1, vec1);
        fillVector(temp2, vec2);

        vector<int> combinedVector = vec1;
        combinedVector.insert(combinedVector.end(), vec2.begin(), vec2.end());

        sort(combinedVector.begin(), combinedVector.end());
        // now we will add these nodes in balanced manner
        Node* finalNode = balanceAddToOtherTree(combinedVector, 0, combinedVector.size()-1);
        return finalNode;
    }
    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);


    Node *root2 = new Node(80);
    root2->left     = new Node(40);
    root2->right = new Node(120);

    Solution s;

    Node* res = s.mergeTwoBalancedBST(root1, root2);
    s.inorder(res);
    return 0;
}