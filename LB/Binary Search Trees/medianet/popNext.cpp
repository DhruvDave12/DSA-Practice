#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    public:
    void helper(TreeLinkNode* root){
        queue<TreeLinkNode*> q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            vector<TreeLinkNode*> vec;

            for(int i=0; i<level; i++){
                TreeLinkNode* temp = q.front();
                q.pop();
                vec.push_back(temp);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            int i;
            for(i=0; i<vec.size()-1; i++){
                vec[i]->next = vec[i+1];
            }
            vec[i]->next = NULL;
        }

    }

    void connect(TreeLinkNode* A){
        helper(A);
    }
};

void tester(TreeLinkNode* x){
    if(!x) return;
    
    tester(x->left);
    TreeLinkNode* t = x;
    while(t){
        cout<<t->val<<"->";
        t=t->next;
    }cout<<"\n";
    tester(x->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    Solution s;
    s.connect(root);

    tester(root);

    return 0;
}