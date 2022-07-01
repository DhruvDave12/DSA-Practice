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
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       if(!root) return ans;

       queue<Node*> q;
       q.push(root);

       while(!q.empty()){
            int level = q.size();
            for(int i=0; i<level; i++){
                Node* temp = q.front();
                q.pop();

                if(i == level-1){
                    ans.push_back(temp->data);    
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
       }

       return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}