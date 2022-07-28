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
    // map<int,int> mp;
    void fillMap(TreeNode* root, map<int,int> &mp){
        if(!root) return;

        fillMap(root->left, mp);
        mp[root->val]++;
        fillMap(root->right, mp);
    }

    void fillPriorityQueue(TreeNode* root, priority_queue<int> &pq){
        if(!root) return;

        fillPriorityQueue(root->left, pq);
        pq.push(root->val);
        fillPriorityQueue(root->right, pq);
    }

    vector<int> findMode2(TreeNode* root) {
        priority_queue<int> pq;
        vector<int> res;
        
        fillPriorityQueue(root, pq);
        int maxFreq = pq.top();

        while(pq.top() == maxFreq){
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }

    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        vector<int> res;
        map<int,int> :: iterator it;
        
        fillMap(root, mp);
        int maxFreq = INT_MIN;
        for(it = mp.begin(); it != mp.end(); it++){
            maxFreq = max(maxFreq, it->second);
        }

        for(it=mp.begin(); it!= mp.end(); it++){
            if(it->second == maxFreq){
                res.push_back(it->first);
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