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
class Solution {
 
    map<Node*, bool> mp;
    vector<int> ans;
    stack<int> helper;
    void getLeaves(Node* root){
        if(!root) return;
        getLeaves(root->left);
        if(root->left == NULL && root->right == NULL){
            if(mp.count(root) == 0){
                mp[root] = true;
                ans.push_back(root->data);
            }
        }
        getLeaves(root->right);
    }

public:
    vector <int> boundary(Node *root)
    {
        Node* leftTemp = root->left;
        Node* rightTemp = root->right;
        Node* leafTemp = root;
        
        ans.push_back(root->data);
        mp[root] = true;
        
        while(leftTemp){
            if(mp.count(leftTemp) == 0){
                ans.push_back(leftTemp->data);
                mp[leftTemp] = true;
            }
            if(leftTemp->left){
                leftTemp = leftTemp->left;
            } else {
                leftTemp = leftTemp->right;
            }
        }

        getLeaves(leafTemp);
        // getLeaves(leafTemp->right);
        
        while(rightTemp){
            if(mp.count(rightTemp) == 0){
                helper.push(rightTemp->data);
                mp[rightTemp] = true;
            }
            if(rightTemp->right){
                rightTemp = rightTemp->right;
            } else{
                rightTemp = rightTemp->left;
            }
        }
        
        while(!helper.empty()){
            ans.push_back(helper.top());
            helper.pop();
        }

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
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    Solution s;
    vector<int> ans = s.boundary(root);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}