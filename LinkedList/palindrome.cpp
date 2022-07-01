#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    
    bool isPalindrome(ListNode *head)
    {
        stack<ListNode*> st;

        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }   
        ListNode* newHead = head;
        // ListNode* newTemp = newHead;

        while(newHead){
            ListNode* x = st.top();
            if(newHead != x){
                return false;
            }
            newHead = newHead->next;
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}