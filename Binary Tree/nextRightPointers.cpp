#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        vector<Node*> vec;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vec.clear();
            for(int i=0; i<n; i++){
                Node* t = q.front();
                q.pop();
                vec.push_back(t);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            int j = 0;
            for(;j<vec.size()-1; j++){
                vec[j]->next = vec[j+1];
            }
            vec[j]->next = NULL;
        }
        
        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}