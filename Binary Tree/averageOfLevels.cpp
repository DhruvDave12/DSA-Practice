#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<double> vec;

    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return vec;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            double sum = 0;
            for(int i=0; i<level; i++){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            sum = sum / level;
            sum = sum * 1.00000;
            vec.push_back(sum);
        }    

        return vec;    
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}