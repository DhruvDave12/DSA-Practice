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
    void fillMap(map<int,pair<int,int>> &m, int verticalLen, int level, Node* root){
        if(!root) return;

        if(m.count(verticalLen) == 0){
            // we dont have any node at this particular depth
            m[verticalLen] = make_pair(root->data, level);
        }
        else if(m[verticalLen].second <= level){
            // else if a node for this depth exists and is at more lower level we replace it
            m[verticalLen] = make_pair(root->data, level);
        }

        fillMap(m, verticalLen-1, level+1, root->left);
        fillMap(m, verticalLen+1, level+1, root->right);
    }

  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(!root) return;
        map<int, pair<int,int>> m;

        fillMap(m,0,0,root);
        vector<int> ans;
        map<int, pair<int,int>> :: iterator itr;

        for(itr = m.begin(); itr != m.end(); itr++){
            ans.push_back(itr->second.first);
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