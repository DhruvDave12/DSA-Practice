#include <bits/stdc++.h>
using namespace std;

class Node{
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

// O(N^2)
Node* constructBSTUtil(vector<int> &pre, int *preIdx, int low, int high, int size){
    if(*preIdx >= size || low > high) return NULL;
    Node* root = new Node(pre[*preIdx]);
    *preIdx = *preIdx+1;

    if(low == high) return root;

    int i;
    for(i=low; i<=high; i++){
        if(pre[i] > root->data)
            break;
    }

    root->left = constructBSTUtil(pre, preIdx, *preIdx, i-1, pre.size());
    root->right = constructBSTUtil(pre, preIdx, i, high, pre.size());

    return root;
}

// O(N) -> working in a range rather than always iterating the array
// we take an element and pass it with a range of min and max
// if we get that element in the range we add it else we dont 
Node* constructBSTUtil2(vector<int> &pre, int *preIdx, int key, int min, int max, int size){
    if(*preIdx >= size) return NULL;

    Node* root = NULL;

    // now if the current element is in range of min to max then only we add it
    if(key > min && key < max){
        root = new Node(key);
        *preIdx = *preIdx + 1;

        if(*preIdx < size){
            // elements less than key will go in left
            root->left = constructBSTUtil2(pre, preIdx, pre[*preIdx], min, key, pre.size());
        }
        if(*preIdx < size){
            // elements greater than key will go in right
            root->right = constructBSTUtil2(pre, preIdx, pre[*preIdx], key, max, pre.size());
        }
    }
    return root;
}



void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void buildTree(vector<int> &pre){
    int preIndex = 0;
    // Node* root = constructBSTUtil(pre,&preIndex,0,pre.size()-1, pre.size());
    Node* root2 = constructBSTUtil2(pre, &preIndex,pre[preIndex], INT_MIN, INT_MAX, pre.size());
    inorder(root2);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> pre = {10, 5, 1, 7, 40, 50};

    buildTree(pre);
    return 0;
}