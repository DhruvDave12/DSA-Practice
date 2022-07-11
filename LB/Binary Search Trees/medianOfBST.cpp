#include <bits/stdc++.h>
using namespace std;

class Node{
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

void fillVector(Node* root, vector<int> &vec){
    if(!root) return;
    fillVector(root->left, vec);
    vec.push_back(root->data);
    fillVector(root->right, vec);
}

float findMedian(struct Node *root)
{
      //Code here
    Node* temp1 = root;
    vector<int> v;
    fillVector(root, v);

    int len = v.size();
    float ans;
    if(len % 2 == 0){
        int x = len / 2;
        ans = (float)(((float)v[x] + (float)v[x-1])/2);
    }
    else{
        int x = (len+1)/2;
        ans = (float)(v[x-1]);
    }

    return ans;
}

float findMedian2Helper(Node* root, int &c, int target, int total, bool &v, float &sum){
    if(!root) return;

    findMedian2Helper(root->left,c,target,total,v,sum);
    c++;
    if(total % 2 != 0){
        if(c == target){
            return (float) root->data;
        }
    }
    if(total % 2 == 0 && !v){
        sum += root->data;
        v = true;
    }
    else if(total%2 == 0 && v){
        sum += root->data;
        return (float)(sum/2);
    }
    findMedian2Helper(root->right,c,target,total,v,sum);

}
int getCountOfNodes(Node* root, int &count){
    if(!root) return 0;
    count++;
    getCountOfNodes(root->left, count);
    getCountOfNodes(root->right, count);
    return count;
}

float findMedian2(struct Node *root)
{
    int c = 0, sum = 0, target, total=0;
    bool v = false;
    Node* temp = root;
    
    total = getCountOfNodes(temp, total);
    if(total % 2 == 0){
        target = 
    }
    return findMedian2Helper(root)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
   
    int x = 0;
    cout<<getCountOfNodes(root, x)<<"\n";
    return 0;
}