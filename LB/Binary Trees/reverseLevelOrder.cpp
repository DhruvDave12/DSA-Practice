#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

// go level wise from bottom
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    queue<Node*> st;
    st.push(root);
    vector<Node*> helper;
    stack<Node*>working;

    while(!st.empty()){
        int nodeCount = st.size();

        while(nodeCount != 0){
            Node* temp = st.front();
            st.pop();
            working.push(temp);
            // ans.push_back(temp);
            if(temp->left){
                st.push(temp->left);
            }
            if(temp->right){
                st.push(temp->right);
            }
            nodeCount--;
        }
        while(!working.empty()){
            helper.push_back(working.top());
            working.pop();
        }
        helper.push_back(NULL);
    }

    for(int i=helper.size()-1; i>=0; i--){
        if(helper[i] != NULL){
            ans.push_back(helper[i]->data);
        }
    }
    
    return ans;
}

vector<int> reverse2(Node* root){
    vector<int> vec;
    if(!root) return vec;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        vec.push_back(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }

    return vec;
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

    Node* temp = root;
    reverseLevelOrder(root);
    cout<<"\nOTHER TECH: "<<"\n";
    vector<int> v = reverse2(temp);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}