#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = NULL, *nextNode = head;

        while(nextNode){
            if(nextNode->val == val){
                prev->next = nextNode->next;
                ListNode* toDelete = nextNode;
                nextNode = nextNode->next;
                delete toDelete;
            }
            else{
                prev = nextNode;
                nextNode = nextNode->next;
            }
        }
        
        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}