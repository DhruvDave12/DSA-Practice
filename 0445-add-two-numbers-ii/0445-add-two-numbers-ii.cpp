/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* node){
        if(!node) return node;
        
        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* nextNode = node->next;
        
        while(nextNode){
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        
        curr->next = prev;
        return curr;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rev1 = reverseList(l1);
        ListNode* rev2 = reverseList(l2);
        // print(rev1);
        // print(rev2);
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        int rem = 0;
        while(rev1 && rev2){
            int x = rev1->val + rev2->val + rem;
            rem = x/10;
            ListNode* newNode = new ListNode(x%10);
            temp->next = newNode;
            temp = temp->next;
            rev1 = rev1->next;
            rev2 = rev2->next;
        }
        
        while(rev1){
            int x = rev1->val + rem;
            rem = x / 10;
            
            ListNode* newNode = new ListNode(x%10);
            temp->next = newNode;
            temp = temp->next;
            rev1 = rev1->next;
        }
        
        while(rev2){
            int x = rev2->val + rem;
            rem = x / 10;
            ListNode* newNode = new ListNode(x%10);
            temp->next = newNode;
            temp = temp->next;
            rev2 = rev2->next;
        }
        
        if(rem != 0){
            temp->next = new ListNode(rem);
            temp = temp->next;
        }
        
        ListNode* ress = reverseList(ans->next);
        
        return ress;
    }
    
    void print(ListNode* l){
        ListNode* temp = l;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
};