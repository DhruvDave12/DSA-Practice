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

    int totalNodes(ListNode* head){
        int temp = 0;
        ListNode* tempNode = head;
        while(tempNode){
            temp++;
            tempNode = tempNode->next;
        }

        return temp;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if(totalNodes(head) == 1){
            return head;
        }
        else if(totalNodes(head) == 2){
            ListNode* curr = head;
            ListNode* curr2 = head->next;
            head = curr2;
            curr2->next = curr;
            curr->next = NULL;
            return head;
        }

        int i = 1;
        int N = totalNodes(head);
        int target2 = N-k+1;

        ListNode* prev1 = head, *prev2 = head, *curr = head, *curr2 = head;
        // taking first node onto kth position
        while(i != k){
            prev1 = curr;
            curr = curr->next;
            i++;
        }

        i = 1;
        while(i != target2){
            prev2 = curr2;
            curr2 = curr2->next;
            i++;
        }

        prev1->next = curr2;
        prev2->next = curr;
        ListNode* temp = curr->next;
        curr->next = curr2->next;
        curr2->next = temp;

        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}