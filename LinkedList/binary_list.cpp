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
    int getDecimalValue(ListNode* head) {
        stack<ListNode*> st;

        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }

        int ans, i=0;

        while(!st.empty()){
            int x = st.top()->val;
            ans = ans + x*pow(2,i);
            i++;
            st.pop();
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}