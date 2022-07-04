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

// Now in this question we are supposed to find the min swaps to convert BT to BST
// We know that in a BST the inorder is always sorted
// so the number of swaps required to convert inorder of BT to sorted order we can get the 
// number of swaps to convert BT to BST
class Solution {
    public:
    vector<int> vec;
    void inorder(Node* root){
        if(!root) return;

        inorder(root->left);
        vec.push_back(root->data);
        inorder(root->right);
    }

    int minSwaps(){
        vector<pair<int,int>> store;

        for(int i=0; i<vec.size(); i++){
            store.push_back({vec[i], i});
        }

        sort(store.begin(), store.end());

        int cycleSize = 0;
        vector<bool> vis(vec.size(), false);
        int ans = 0;
        for(int i=0; i<store.size(); i++){
            if(vis[i] || store[i].second == i){
                continue;
            }

            int j = i;
            cycleSize = 0;

            while(!vis[j]){
                vis[j] = true;
                j = store[j].second;
                cycleSize++;
            }

            if(cycleSize > 0){
                ans += cycleSize;
            }
        }
        return ans;
    }

    int minSwapsToConvertBTToBST(Node* root){
        if(!root) return 0;

        inorder(root);
        int ans = minSwaps();

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    return 0;
}