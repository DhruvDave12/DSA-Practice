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

// this is method 1 but GFG test cases doesnt handle this code but it is correct.(Forming trees and checking);

class Solution {
  public:

  void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }

    Node* buildTree(int e, int A[]){
        Node* root = NULL;
        bool flag = false;
        Node* temp = root;
        for(int i=0; i<2*e; i++){
            if(i==0){
                root = new Node(A[i]);
                temp = root;
                continue;
            }
            // this is to get temp to the correct position
            else if(i%2==0){
                if(temp->left && A[i] == (temp->left)->data){
                    temp = temp->left;
                }
                else if(temp->right && A[i] == (temp->right)->data){
                    temp = temp->right;
                }
                continue;
            }
            else {
                if(!flag){
                    temp->left = new Node(A[i]);
                    flag = true;
                }
                else if(flag){
                    temp->right = new Node(A[i]);
                    flag = false;
                }
            }
        }

        return root;
    }

    bool isMirror(Node* root1, Node* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        return (root1->data == root2->data && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
    }

    int checkMirrorTree(int n, int e, int A[], int B[]) {
        Node* root1 = buildTree(e,A);
        Node* root2 = buildTree(e,B);
        // Now we have the trees from the array now we are just supposed to check both the trees
        if(isMirror(root1, root2)){
            return 1;
        }
        return 0;
    }
};

// this solution is handled by GFG
class Solution2 {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        map<int, stack<int>> mp;
// if you wanna check if the trees are same or not with this method make a  hash map of 
        for(int i=0; i<2*e; i+=2){
            mp[A[i]].push(A[i+1]);
        }
        for(int i=0; i<2*e; i+=2){
            if(mp[B[i]].top() != B[i+1]){
                return 0;
            }
            mp[B[i]].pop();
        }
        return 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int e = 1;

    int A[] = {1,2};
    int B[] = {1,2};

    Solution s;
    int ans = s.checkMirrorTree(3,e,A,B);
    if(ans == 1){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }

    return 0;
}