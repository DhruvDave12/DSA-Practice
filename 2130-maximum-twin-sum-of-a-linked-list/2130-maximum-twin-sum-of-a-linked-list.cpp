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
    
    int pairSum(ListNode* head) {
        if(!head) return 0;
        
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        int len = getLen(temp1);
        int i = 0;
        stack<int> st;
        while(i != len/2 && temp2){
            st.push(temp2->val);
            temp2 = temp2->next;
            i++;
        }
        
        int res = 0;
        int sum = 0;
        while(temp2){
            sum = temp2->val + st.top();
            res = max(res,sum);
            st.pop();
            temp2 = temp2->next;
        }
        
        return res;
    }
};