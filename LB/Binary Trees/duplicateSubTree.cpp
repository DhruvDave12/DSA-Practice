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
    // vector<string> vec;
    map<vector<int>,int> mp;
    vector<int> v;
    public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    void inorder(Node* root){
        if(!root) return;
        
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }
    void fillMap(Node* root){
        if(!root) return;
        inorder(root);
        mp[v]++;
        v.clear();
    }

    int dupSub(Node *root) {
        if(!root) return 0;
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            Node* newTemp = temp;
            fillMap(newTemp);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        map<vector<int>,int> :: iterator itr;
        for(itr = mp.begin(); itr != mp.end(); itr++){
            if(itr->second > 1 && itr->first.size() > 1) return 1;
        }
        return 0;
    }
};

class Solution2 {
    public:
    string fillMap(Node* root, map<string, int> &mp){
        if(!root) {
            return "#";
        }
        string l = fillMap(root->left,mp);
        string r = fillMap(root->right,mp);
        string temp = to_string(root->data) + l + r;
        if(!(l == "#" && r == "#")){
            mp[temp] ++;
        }
        // cout<<temp<<"\n";
        return temp;
    }

    int dupSub(Node* root){
        map<string, int> mp;
        string s;
        fillMap(root, mp);
        map<string,int> :: iterator it;
        for(it = mp.begin(); it!=mp.end(); it++){
            if(it->second > 1){
                return 1;
            }
        }
        return 0;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(5);

    Solution2 s;

    int ans = s.dupSub(root);

    if(ans == 1){
        cout<<"\nYES"<<"\n";
    } else {
        cout<<"\nNO"<<"\n";
    }
    return 0;
}