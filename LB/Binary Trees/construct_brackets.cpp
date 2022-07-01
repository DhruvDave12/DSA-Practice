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

Node* constructTree(string s){
    Node* root;
    int open = 0;
    int close = 0;
    stack<int> st;

    for(int i=0; i<s.length()-1; i++){
        if(s[i+1] == '(' && s[i] != ')'){
            root = new Node(s[i]-'0');
            open++;
        }
        else if(s[i] != ')' && s[i] != '('){
            if(open&2 != 0 && close % 2 == 0){
                st.push(s[i]-'0');
            }
        } 
        else if(s[i] == ')'){
            close ++;
            root->left = new Node(st.top());
            st.pop();
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}