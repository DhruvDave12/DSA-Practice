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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* res = new ListNode(-1);
        ListNode* t = res;

        ListNode* odd = head;
        ListNode* even = head->next;

        while(odd && odd->next){
            // cout<<"ODD: "<<odd->val<<"\n";
            t->next = new ListNode(odd->val);
            t = t->next;
            odd = odd->next->next;
        }
        if(odd && !odd->next){
            t->next = new ListNode(odd->val);
            t = t->next;
        }
        // t->next = new ListNode(odd->val);
        // t = t->next;

        while(even && even->next){
            t->next = new ListNode(even->val);
            t = t->next;
            even = even->next->next;
        }
        if(even && !even->next){
            t->next = new ListNode(even->val);
            t = t->next;
        }
        // t->next = new ListNode(even->val);
        // t = t->next;
        return res->next;
    }
};

void traverse(ListNode* head){
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);

    Solution s;

    ListNode* res = s.oddEvenList(head);

    traverse(res);
    return 0;
}