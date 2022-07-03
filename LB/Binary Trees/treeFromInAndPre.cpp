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

class Solution{
    public:
    int searchIdx(int in[], int key, int n){
        for(int i=0; i<n; i++){
            if(in[i] == key){
                return i;
            }
        }
        return -1;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        if(n == 0) return NULL;
        Node* root = new Node(pre[0]);
        int idx = searchIdx(in, pre[0], n);
        root->left = buildTree(in, pre+1, idx);
        root->right = buildTree(in+idx+1, pre+idx+1, n-idx-1);
        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}