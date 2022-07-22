#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode* next;
    ListNode(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    
    struct ListNode* reverse(struct ListNode* head){
        if(!head || !head->next){
            return head;
        }    
        
        struct ListNode* prev = NULL;
        struct ListNode* curr = head;
        struct ListNode* nextListNode = head->next;
        
        while(nextListNode){
            curr->next = prev;
            prev = curr;
            curr = nextListNode;
            nextListNode = nextListNode->next;
        }
        
        curr->next = prev;
        return curr;
    }
    
    //Function to add two numbers represented by linked list.
    struct ListNode* addTwoLists(struct ListNode* first, struct ListNode* second)
    {
        struct ListNode* rev1 = reverse(first);
        struct ListNode* rev2 = reverse(second);
        
        struct ListNode* ans = new ListNode(-1);
        struct ListNode* temp = ans;
        int carry = 0;
        
        while(rev1 && rev2){
            // build the logic here ...
            int sum = rev1->data + rev2->data + carry;
            // if(!temp){
            //     temp = new ListNode(sum%10);
            // }
            // else{
                temp->next = new ListNode(sum%10);
                temp = temp->next;
            // }
            carry = sum/10;
            rev1 = rev1->next;
            rev2 = rev2->next;
        }
        
        if(rev1){
            while(rev1){
                int sum = rev1->data + carry;
                temp->next = new ListNode(sum%10);
                carry = sum/10;
                temp = temp->next;
                rev1 = rev1->next;
            }
        }
        
        if(rev2){
            while(rev2){
                int sum = rev2->data + carry;
                temp->next = new ListNode(sum);
                carry = sum/10;
                temp = temp->next;
                rev2 = rev2->next;
            }
        }
        if(carry == 1){
            temp->next = new ListNode(1);
        }
        ans = ans->next;
        struct ListNode* finalRes = reverse(ans);
        return finalRes;
    }
};

void traverse(struct ListNode* head){
    struct ListNode* temp = head;

    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    struct ListNode* head = new ListNode(9);
    head->next = new ListNode(4);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(6);
    
    struct ListNode* head1 = new ListNode(6);
    // head1->next = new ListNode(5);

    Solution s;
    struct ListNode* ans = s.addTwoLists(head, head1);

    traverse(ans);
    return 0;
}