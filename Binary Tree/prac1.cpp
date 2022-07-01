#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int x){
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertLevelOrder(vector<int> nodes, int i){
    Node* root = NULL;
    if(i<nodes.size()){
        Node* newNode = new Node(nodes[i]);
        root = newNode;

        root->left = insertLevelOrder(nodes, 2*i + 1);
        root->right = insertLevelOrder(nodes, 2*i + 2);
    }
    return root;
}

// Inorder
void printTreeDFS(Node* root){
    if(root == NULL){
        return;
    }
    printTreeDFS(root->left);
    cout<<root->val<<" ";
    printTreeDFS(root->right);
}

vector<int> v;
void getBeautiful(Node* root, int x){
    if(root == NULL){
        return;
    }
    int val = root->val; 
    // cout<<"VAL: "<<val<<"\n";
    int temp = val, z=0;
    while(temp!=0){
        int rem = temp % 10;
        z = z + (rem*rem);
        temp /= 10;
    }
    if(z <= x){
        v.push_back(z);
    }

    getBeautiful(root->left, x);
    getBeautiful(root->right, x);
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    } 

    Node* root = insertLevelOrder(vec, 0);
    // printTreeDFS(root);

    getBeautiful(root, 10);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}