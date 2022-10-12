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
    
    int getLen(ListNode* head){
        ListNode* temp = head;
        int curr = 0;
        while(temp){
            curr++;
            temp = temp->next;
        }
        
        return curr;
    }
    
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        int len = getLen(temp);
        ListNode* temp2 = head;
        if(len == 1) return true;
        int i = 0;
        while(i != len/2 && temp2){
            st.push(temp2->val);
            temp2 = temp2->next;
            i++;
        }
        
        if(len % 2 != 0) temp2 = temp2->next;
        
        if(!temp2) return false;
        
        while(temp2){
            if(st.top() != temp2->val) return false;
            temp2 = temp2->next;
            st.pop();
        }
        
        return true;
    }
};