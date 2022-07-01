#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
    Logic:
    1. Go to middle node
    2. Push all later bitches into fckin stack
    3. Make a new loop. Roll over it till mid
    4. While rolling pop those late bitches and add them to the current fucks
    5. Return the max of em.
    6. Fuck leetcode....
*/

class Solution {
public:
    int totalNodes (ListNode* head){
        int temp = 0;
        ListNode* tempNode = head;
        while(tempNode){
            temp++;
            tempNode = tempNode->next;
        }

        return temp;
    }

    int pairSum(ListNode* head) {
        int sum = INT_MIN;
        ListNode* middleNode = head;
        int N = totalNodes(head);
        int i = 0;
        while(i != N/2){
            i++;
            middleNode = middleNode->next;
        }

        ListNode* middleCopy = middleNode;
        stack<ListNode*> st;
        while(middleCopy){
            st.push(middleCopy);
            middleCopy = middleCopy->next;
        }

        int j=0;
        ListNode* finalNodePtr = head;
        while(j != N/2 - 1){
            sum = max(st.top()->val + finalNodePtr->val, sum);
            st.pop();
            finalNodePtr = finalNodePtr->next;
        }
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}