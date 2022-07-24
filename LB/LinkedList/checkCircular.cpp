#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

bool isCircular(Node *head)
{
   // Your code here
   if(!head) return true;
   map<Node*,int> mp;

    Node* temp = head;
    while(temp){
        if(mp[temp] > 1){
            return true;
        }
        mp[temp]++;
        temp = temp->next;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* head = new Node(1);
    Node* t = head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    if(isCircular(head)){
        cout<<"YES IS CIRCULAR"<<"\n";
    } else {
        cout<<"NO IT IS NOT CIRCULAR"<<"\n";
    }
    return 0;
}