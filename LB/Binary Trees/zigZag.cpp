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
    vector<int> helper;
    public:
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
        if(!root) return ans;
        queue<Node*> mainQ;
        mainQ.push(root);
        int check = 0;
        while(!mainQ.empty()){
            int n = mainQ.size();
            for(int i=0; i<n; i++){
                Node* temp = mainQ.front();
                mainQ.pop();
                helper.push_back(temp->data);
                if(temp->left) mainQ.push(temp->left);
                if(temp->right) mainQ.push(temp->right);
            }

            if(check%2==0){
                for(int i=0; i<helper.size(); i++){
                    ans.push_back(helper[i]);
                }
            }
            else{
                for(int i=helper.size()-1; i>=0; i--){
                    ans.push_back(helper[i]);
                }
            }
            helper.clear();
            check++;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}