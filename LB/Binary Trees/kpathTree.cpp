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

void printVector(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }cout<<endl;
}
void checkSumAndFillVector(vector<int> &vec, int k, Node* root){
    if(!root) return;

    vec.push_back(root->data);

    checkSumAndFillVector(vec,k,root->left);
    checkSumAndFillVector(vec,k,root->right);
    
    int currSum = 0;
    // now check the vector if any path with sum k
    for(int j=vec.size()-1; j>=0; j--){
        currSum += vec[j];

        if(currSum == k){
            printVector(vec);
        }    
    }

    // removing current element 
    vec.pop_back();

}
void printKPath(Node* root, int k){
    vector<int> ans;
    checkSumAndFillVector(ans,k,root);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
 
    int k = 5;
    printKPath(root, k);
    return 0;
}