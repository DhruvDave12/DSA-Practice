/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* prev = node;
        ListNode* temp = node->next;
        
        ListNode* beforePrev = NULL;
        while(temp){
            prev->val = temp->val;
            beforePrev = prev;
            prev = temp;
            temp = temp->next;
        }
        
        beforePrev->next = NULL;
    }
};