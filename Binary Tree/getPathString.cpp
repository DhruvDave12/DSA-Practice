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

class Solution
{
public:
    void binaryTreeString(TreeNode *root, string &s, vector<string> &vec)
    {
        if (!root)
            return;
        if ((!root->left) && (!root->right))
        {
            string toInsert = to_string(root->val);
            s.append(toInsert);
            for(int k=0; k<s.length(); k++){
                if(s[k] == '~'){
                    s[k] = '-';
                }
            }
            vec.push_back(s);
            return;
        }
        string toInsert = to_string(root->val);
        s.append(toInsert);
        s.append("~>");
        if (root->left)
        {
            binaryTreeString(root->left, s, vec);
            int j = s.length()-1;
            while(s[j] == '~' || s[j] == '>'){
                s.pop_back();
                j = s.length()-1;
            }
            while(s[j] != '~' && s[j] != '>'){
                s.pop_back();
                j = s.length()-1;
            }
            // cout<<"HERE S: "<<s<<"\n";
        }

        if (root->right)
        {
            binaryTreeString(root->right, s, vec);
            // int j = s.length();
            // while(s[j] == '-' || s[j] == '>'){
            //     s.pop_back();
            // }
            int j = s.length()-1;
            while(s[j] == '~' || s[j] == '>'){
                s.pop_back();
                j = s.length()-1;
            }
            while(s[j] != '~' && s[j] != '>'){
                s.pop_back();
                j = s.length()-1;
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> vec;
        string s = "";
        binaryTreeString(root, s, vec);
        return vec;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(100);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(-34);

    Solution s;

    vector<string> vec = s.binaryTreePaths(root);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "\n";
    }
    return 0;
}