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

class Solution
{
public:

    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2){
        ListNode* merged = new ListNode(-1);
        ListNode* tempMerge = merged;

        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                tempMerge->next = new ListNode(temp1->val);
                temp1 = temp1->next;        
            }
            else{
                tempMerge->next = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            tempMerge = tempMerge->next;
        }

        if(temp1){
            while(temp1){
                tempMerge->next = new ListNode(temp1->val);
                temp1 = temp1->next;
                tempMerge = tempMerge->next;
            }
        }

        if(temp2){
            while(temp2){
                tempMerge->next = new ListNode(temp2->val);
                temp2 = temp2->next;
                tempMerge = tempMerge->next;
            }
        }

        ListNode* temp10 = merged->next;
        return merged->next;
    }

    ListNode* mergeSort(ListNode* start){
        if(!start || !start->next) return start;
        ListNode* temp = NULL;
        ListNode* mid = start;
        ListNode* fast = start;
        while(fast && fast->next){
            temp = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        // cout<<"MID VAL: "<<mid->val<<"\n";
        ListNode* l1 = mergeSort(start);
        ListNode* l2 = mergeSort(mid);
        ListNode* res = mergeTwoLists(l1, l2);
        return res;
    }

    ListNode *sortList(ListNode *head)
    {
        if(!head) return NULL;
        ListNode* temp = head;

        ListNode* tempRes = mergeSort(temp);
        return tempRes;
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

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;

    head = s.sortList(head);
    traverse(head);
    return 0;
}