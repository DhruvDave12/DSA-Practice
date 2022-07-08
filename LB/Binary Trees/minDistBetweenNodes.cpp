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

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lcaUtil1(Node* root, int n1, int n2, bool &v1, bool &v2){
        if(!root) return NULL;
        
        if(root->data == n1) {
            v1 = true;
            return root;
        }
        if(root->data == n2){
            v2 = true;
            return root;
        }
        
        Node* leftLCA = lcaUtil1(root->left, n1,n2,v1,v2);
        Node* rightLCA = lcaUtil1(root->right, n1,n2,v1,v2);
        
        if(leftLCA && rightLCA) return root;
        
        return leftLCA ? leftLCA : rightLCA;
    }
    
    bool find(Node* root, int k){
        if(!root) return false;
        
        if(root->data == k || find(root->left, k) || find(root->right, k)) return true;
        
        return false;
    }
    
    Node* getLCA(Node* root, int n1, int n2) {
        if(!root) return NULL;
        
        bool v1 = false, v2 = false;
        Node* lca = lcaUtil1(root,n1,n2,v1,v2);
        
        if(v1&&v2 || (v1 && find(root, n2)) || (v2 && find(root, n1))){
            return lca;
        }
        
        return NULL;
    }
    
    // does pass GFG Test Cases but may fail in real life for that make a map for <Node*, int>
    map<int, int> mp;
    void getLevel(Node* root, int key, int level){
        if(!root) return;
        
        // cout<<root->data<<" "<<key<<"\n";
        if(root->data == key) {mp[root->data] = level;}
        
        getLevel(root->left, key, level+1);
        getLevel(root->right, key, level+1);
    }
    
    int findDist(Node* root, int a, int b) {
        Node* tempRoot = root, *tempRoot1 = root, *tempRoot2 = root;
        Node* lca = getLCA(root, a, b);
        
        getLevel(tempRoot, lca->data, 0);
        getLevel(tempRoot1, a, 0);
        getLevel(tempRoot2, b, 0);
        
        // cout<<"LCA LEVEL: "<<mp[lca->data]<<"\n"<<"N1: "<<mp[a]<<"\n"<<"N2: "<<mp[b]<<"\n";
        // return (n1Level-lcaLevel) + (n2Level-lcaLevel);
        return (mp[a]-mp[lca->data]) + (mp[b]-mp[lca->data]);
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}