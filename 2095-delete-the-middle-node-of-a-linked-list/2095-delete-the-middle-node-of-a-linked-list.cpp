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
    
    int getLen(ListNode*  head){
        ListNode* temp = head;
        int curr = 0;
        while(temp){
            curr++;
            temp = temp->next;
        }
        
        return curr;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode* temp = head;
        int len = getLen(temp);
        int i = 0;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(i != len/2 && curr){
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        prev->next = curr->next;
        delete curr;
        
        return head;    
    }
};