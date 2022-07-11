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

class Solution
{
public:

    void fillVector(Node* root, vector<int> &vec, int x){
        if(!root) return;
        fillVector(root->left, vec, x);
        if(root->data <= x){
            vec.push_back(abs(root->data - x));
        }
        fillVector(root->right, vec, x);
    }

    bool searchVal(Node* root, int key){
        if(!root) return false;
        if(root->data == key) return true;

        if(root->data > key){
            return searchVal(root->left, key);
        }
        if(root->data < key){
            return searchVal(root->right, key);
        }
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> needed;
        Node* temp1 = root1;
        fillVector(temp1, needed, x);

        // now we have search these pairs
        int res = 0;

        for(int i=0; i< needed.size(); i++){
            Node* temp2 = root2;
            if(searchVal(temp2, needed[i])){
                res++;
            }
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}