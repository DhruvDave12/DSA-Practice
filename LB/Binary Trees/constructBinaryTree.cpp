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

class Solution{
    public:
    // this routine gives us the corresponding closing bracket index for opening index given
    int getRespIndex(string str, int si, int ei){
        if(si > ei){
            return -1;
        }
        stack<char> st;
        for(int i = si; i <= ei; i++){
            if(str[i] == '('){
                st.push(str[i]);
            }    
            else if(str[i] == ')'){
                if(st.top() == '('){
                    st.pop();
                }

                if(st.empty()){
                    return i;
                }
            }
        }
        return -1;
    }

    Node* constructTree(string str, int si, int ei){
        if(si > ei){
            return NULL;
        }

        Node* root = new Node(str[si] - '0');
        int idx = -1;
        if(si+1 <= ei && str[si+1] == '('){
            idx = getRespIndex(str, si+1, ei);
        }

        if(idx != -1){
            // we got the index so we will now add them in root left and right
            root->left = constructTree(str, si+2, idx-1);
            root->right = constructTree(str,idx+2, ei-1);
        }

        return root;
    }

    void inorder(Node* root){
        if(!root) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str = "4(2(3)(1))(6(5))";

    Solution s;

    Node* root = s.constructTree(str, 0, str.length()-1);

    s.inorder(root);
    return 0;
}