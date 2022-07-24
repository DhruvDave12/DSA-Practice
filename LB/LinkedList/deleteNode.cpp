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
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* ptr = node->next;
        while(ptr){
            curr->val = ptr->val;
            curr = curr->next;
            ptr = ptr->next;
        }

        curr = NULL;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}