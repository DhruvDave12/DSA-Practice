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

void inorder(Node* root, vector<int> &vec){
    if(!root) return;
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}

vector<Node*> printAllDups(Node* root)
{
    map<vector<int>, pair<Node*, int>> mp;
    vector<Node*> result;
    if(!root) return result;

    stack<Node*> st;
    stack<Node*> out;
    st.push(root);
    vector<int>vec;
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        out.push(temp);
        if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
    }

    while(!out.empty()){
        vec.clear();
        Node* temp = out.top();
        inorder(out.top(), vec);
        mp[vec].first = temp;
        mp[vec].second ++;
        out.pop();
    }
    map<vector<int>, pair<Node*,int>> :: iterator it;

    for(it=mp.begin(); it!=mp.end(); it++){
        if(it->second.second > 1){
            result.push_back(it->second.first);
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    printAllDups(root);
    return 0;
}