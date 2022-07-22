#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *nextNode = head->next;

        while (nextNode)
        {
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        curr->next = prev;
        return curr;
    }

    Node *addOne(Node *head)
    {
        Node *revHead = reverse(head);
        Node *temp = revHead;
        Node *prev = NULL;
        
        while (temp && temp->data == 9)
        {
            temp->data = 0;
            prev = temp;
            temp = temp->next;
        }
        if (temp)
        {
            temp->data += 1;
        }
        else
        {
            // cout<<prev->data<<"PREV";
            prev->next = new Node(1);
        }

        Node *res = reverse(revHead);
        return res;
    }
};

void traverse(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head = new Node(9);
    // head->next = new Node()

    Solution s;

    Node* res = s.addOne(head);

    traverse(res);
    return 0;
}