#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};

int getLen(Node* head){
    Node* temp = head;
    int counter = 0;
    while(temp){
        counter++;
        temp = temp->next;
    }
    return counter;
}

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* temp = head;
    int len = getLen(temp);
    int mid = ceil((double)len/2);
    int c = 1;
    Node* temp1 = head;
    while(c!=mid){
        temp1 = temp1->next;
        c++;
    }

    *head2_ref = temp1->next;
    temp1->next = NULL;
    *head1_ref = head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}