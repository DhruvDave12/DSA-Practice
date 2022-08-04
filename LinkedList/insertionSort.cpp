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

void traverse(ListNode* head){
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<"\n";
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        ListNode* temp = new ListNode(-5001);
        ListNode* prev = temp;
        while(cur){
            ListNode* nxt = cur->next;
            if(prev->val >= cur->val)
                prev = temp;
            while(prev->next && prev->next->val < cur->val)
                prev = prev->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = nxt;
        }
        return temp->next;
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;

    head = s.insertionSortList(head);
    traverse(head);

    return 0;
}