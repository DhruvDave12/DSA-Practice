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
    
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        ListNode* prev = NULL;
        
        while(curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
    
        ListNode* temp = head;
        while(temp){
            ListNode* toRev = temp->next;
            temp->next = reverseList(toRev);
            temp = temp->next;
        }
        
    }
};

class Solution2 {
    public:
    void fillMap(ListNode* head, map<int,ListNode*> &mp){
        ListNode* temp = head;
        int i=0;
        while(temp){
            mp[i] = temp;
            i++;
            temp = temp->next;
        }
    }   
    int getLen(ListNode* head){
        int counter = 0;
        ListNode* temp = head;

        while(temp){
            counter++;
            temp = temp->next;
        }

        return counter;
    } 

    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* temp3 = head;
        map<int,ListNode*> mp;
        fillMap(temp3, mp);
        int N = getLen(temp);
        int i = 0;
        int x = 0;
        while(temp2){
            if(x%2==0){
                temp2->val = mp[i]->val;
            } else {
                temp2->val = mp[N-i-1]->val;
                i++;
            }
            
            temp2 = temp2->next;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}