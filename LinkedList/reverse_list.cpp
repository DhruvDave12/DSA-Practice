#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head->next || !head){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nextNode = head->next;

        while(nextNode){
            current->next = prev;
            prev = current;
            current = nextNode;
            nextNode = nextNode->next;
        }

        return head;
    }

    void printList(ListNode* head){
        ListNode* temp = head;
        while(temp){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}