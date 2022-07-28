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

// implementational solution
class myDS {
    public:
    int key;
    vector<int> vec;
};

class Solution {
public:
    vector<int> vec;
    void storeInorder(TreeNode* root, vector<int> &vec){
        if(!root) return;
        storeInorder(root->left, vec);
        vec.push_back(root->val);
        storeInorder(root->right, vec);
    }
    
    void fillMap(TreeNode* root, vector<myDS> &v){
        if(!root) return;
        fillMap(root->left, v);

        TreeNode* temp = root;
        vec.clear();
        storeInorder(temp, vec);
        myDS t;
        t.key = root->val;
        t.vec = vec;
        v.push_back(t);

        fillMap(root->right,v);
    }
    
    bool checkVec(vector<int> vec1, vector<int> vec2){
        if(vec1.size() != vec2.size()) return false;
        for(int i=0; i<vec1.size(); i++){
            if(vec1[i] != vec2[i]) return false;
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<myDS> vecc;
        TreeNode* temp = root;
        fillMap(root, vecc);
        vector<int> toCheck;
        TreeNode* s = subRoot;
        storeInorder(subRoot, toCheck);
        
        for(int i=0; i<vecc.size(); i++){
            if(vecc[i].key == s->val){
                if(checkVec(vecc[i].vec, toCheck)){
                    return true;
                }
            }
        }
        return false;
    }
};


// faster solution
class Solution2{
    public:

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;

        TreeNode* temp = root, *temp2 = subRoot;
        if(isSame(temp,temp2)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }

    bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;

        return p==q && isSame(p->left,q->left) && isSame(p->right, q->right);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}