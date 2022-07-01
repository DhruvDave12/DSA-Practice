#include <bits/stdc++.h>
using namespace std;

// Tree Node ADT (Abstract Data Type)
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        this->data = x;
        this->left = this->right = NULL;
    }
};

Node* insertNode(Node* root, int data){
    if(root == NULL){
        // if root is null then we create a node and return
        root = new Node(data);
        return root;
    }

    // else we travel level order wise using queue
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left != NULL){
            // if does exist then we push it inside the queue
            q.push(temp->left);
        }
        else{
            temp->left = new Node(data);
            return root;
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        else{
            temp->right = new Node(data);
            return root;
        }
    }
}

// Deletion (In binary tree we delete the node and replace it with the right most deepest node)
void deleteGivenNode(Node* root, Node* deepNode){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == deepNode){
            temp = NULL;
            delete deepNode;
            return;
        }

        if(temp->left){
            if(temp->left == deepNode){
                temp->left = NULL;
                delete deepNode;
                return;
            }
            else{
                q.push(temp->left);
            }
        }

        if(temp->right){
            if(temp->right == deepNode){
                temp->right = NULL;
                delete deepNode;
                return;
            }
            else{
                q.push(temp->right);
            }
        }
    }
}

Node* deletion(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->data == key){
            return NULL;
        }
        return root;
    }
    queue<Node*> q;
    q.push(root);
    Node* tempToDel = NULL;
    Node* temp = NULL;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == key){
            tempToDel = temp;
        }
        if(temp->left != NULL){
             q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    if(tempToDel != NULL){
        // Now we will take the last node i.e., temp and put its data in a variable and then delete this node
        int val = temp->data;
        deleteGivenNode(root, temp);
        tempToDel->data = val;
    }
    return root;
}

void travelInorder(Node* root){
    if(root == NULL){
        return;
    }

    travelInorder(root->left);
    cout<<root->data<<" ";
    travelInorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};

    Node* root = NULL;

    for(int i=0; i<arr.size(); i++){
        root = insertNode(root, arr[i]);
    }

    cout<<"BEFORE: "<<"\n";
    travelInorder(root);    

    Node* newNode = deletion(root, 5);
    
    cout<<"\n"<<"AFTER: "<<"\n";
    travelInorder(newNode);

    return 0;
}