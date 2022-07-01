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

// left view means that what would tree look like if i check from left side
// queue
vector<int> leftView(Node *root){
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int level = q.size();
        for(int i=0; i<q.size(); i++){
            Node* temp = q.front(); q.pop();
            if(i == 0){
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

// here we are doing same level order stuff but using recursion and maintaining a level.
void leftUtilRecur(Node* root, int level, int *maxLevel){
    if(!root) return;
    if(level > *maxLevel){
        cout<<root->data<<" ";
        *maxLevel = level;
    }
    leftUtilRecur(root->left, level+1, maxLevel);
    leftUtilRecur(root->right, level+1, maxLevel);
}   

void leftViewRecurWrapper(Node* root){
    if(!root) return;
    int maxLevel = 0;
    leftUtilRecur(root, 1, &maxLevel);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    vector<int> finalAns = leftView(root);

    for(int i=0; i<finalAns.size(); i++){
        cout<<finalAns[i]<<" ";
    }

    cout<<"\n";

    leftViewRecurWrapper(root);
    return 0;
}