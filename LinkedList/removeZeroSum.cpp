#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    void deleteNodes(ListNode* from, ListNode* till){
        ListNode* prev = NULL;
        ListNode* curr = from;

        while(curr != till){
            if(!prev) {
                ListNode* toDel = curr;
                curr = curr->next;
                delete toDel;
            }
            else {
                ListNode* toDel = curr;
                prev->next = curr->next;
                prev = curr;
                curr = curr->next;
                delete toDel;         
            }
        }

        // now we will delete the last node
        ListNode* toDel = curr;
        prev->next = curr->next;
        curr = curr->next;
        delete toDel;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> mp;
        int sum = 0;  
        ListNode* temp = head;
        ListNode* from = head;

        while(temp){
            if (temp->val >= 0) {
                sum += temp->val;
                mp[sum] = temp;
                temp = temp->next;
            }
            else {
                if(mp.count(temp->val) != 0) {
                    int x = temp->val;
                    temp = temp->next;
                    deleteNodes(from, mp[x]);                    
                } else {
                    sum = 0;
                    temp = temp->next;
                }
            }
        }

        return head;
    }
};

void traverse(ListNode* head){
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    Solution s;
    head = s.removeZeroSumSublists(head);
    traverse(head);

    return 0;
}