#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    void fillStringPre(TreeNode* root, string &s){
        if(!root) return;

        s += to_string(root->val);
        s+="$";
        fillStringPre(root->left, s);
        fillStringPre(root->right, s);
    }


    TreeNode* buildTree(vector<int> preorder, int key, int max, int min, int size, int *preIdx){
        if(*preIdx >= size) return NULL;
        TreeNode* root = NULL;

        if(key > min && key < max){
            root = new TreeNode(key);
            *preIdx = *preIdx + 1;
            if(*preIdx < size){
                root->left = buildTree(preorder, preorder[*preIdx], key, min, size, preIdx);
            }
            if(*preIdx < size){
                root->right = buildTree(preorder, preorder[*preIdx], max, key, size, preIdx);
            }
        }
        return root;
    }

    vector<int> getPreOrder(string data){
        vector<int> preorder;
        string s = "";
        for(int i=0; i<data.length(); i++){
            if(data[i] != '$'){
                s += data[i];
            }
            else if(data[i] == '$'){
                int size = s.length()-1;
                int j = 0;
                int data = 0;
                while(j < s.length()){
                    data += (s[j]*pow(10, size));
                    size--;
                    j++;
                }
                preorder.push_back(data);
                s = "";
            }
        }

        return preorder;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        TreeNode* temp1 = root;
        fillStringPre(temp1, data);

        return data;
    }

    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder = getPreOrder(data);
        
        int preIdx = 0;
        TreeNode* root = buildTree(preorder, preorder[0], INT_MAX, INT_MIN, preorder.size(), &preIdx);

        return root;
    }
};


void print(TreeNode* root){
    if(!root) return;

    print(root->left);
    cout<<root->val;
    print(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Codec c1;
    Codec c2;

    string tree = c1.serialize(root);
    TreeNode* res = c2.deserialize(tree);

    print(res);
    return 0;
}