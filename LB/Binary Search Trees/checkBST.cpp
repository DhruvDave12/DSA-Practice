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
    vector<int> vec;
    Node* prevNode = NULL;
    bool flag = true;

    void helper1(Node* root){
        if(!root) return;

        helper1(root->left);
        vec.push_back(root->data);
        helper1(root->right);
    }

    bool isBSTMethod1(Node* root){
        helper1(root);

        for(int i=0; i<vec.size()-1; i++){
            if(vec[i+1] < vec[i]) return false;
        }
        return true;
    }

    void helper2(Node* root){
        if(!root) return;

        helper2(root->left);
        if(prevNode && prevNode->data > root->data){
            flag = false;
        }
        prevNode = root;
        helper2(root->right);
    }

    bool isBSTMethod2(Node* root){
        helper2(root);
        return flag;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}