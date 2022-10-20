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
    void _insert(ListNode* head, int val){
        if(!head){
            head = new ListNode(val);
            return;
        }
        ListNode* temp = head;
        while(temp && temp->next){
            temp = temp->next;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    ListNode* _mergeTwoLists(ListNode* list1, ListNode* list2){
        if(!list1 && list2) return list2;
        if(list1 && !list2) return list1;
        if(!list1 && !list2) return NULL;
        ListNode* temp1 = list1, *temp2 = list2;
        ListNode* res;
        
        // should come here only if temp1 and temp2 exists
        if(temp1->val < temp2->val) {
            res = temp1;
            temp1 = temp1->next;
        } else {
            res = temp2;
            temp2 = temp2->next;
        }
        ListNode* t = res;
        
        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                t->next = temp1;
                temp1 = temp1->next;
                t = t->next;
            } else {
                t->next = temp2;
                temp2 = temp2->next;
                t = t->next;
            }
        }
        
        while(temp1){
            t->next = temp1;
            temp1 = temp1->next;
            t = t->next;
        }
        
        while(temp2){
            t->next = temp2;
            temp2 = temp2->next;
            t = t->next;
        }
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        ListNode* head = new ListNode(-1);
    
        head->next = lists[0];
        head = head->next;
        
        for(int i=1; i<lists.size(); i++){
            // compare head and list[i]
            head = _mergeTwoLists(head, lists[i]);
        }
        
        return head;
    }
};