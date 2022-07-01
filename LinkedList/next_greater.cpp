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
    int totalNodes(ListNode* head) {
        ListNode* temp = head;
        int x = 0;
        while(temp){
            x++;
            temp = temp->next;
        }
        
        return x;
    }

    vector<int> nextLargerNodes(ListNode *head)
    {   
        if(head->next == NULL){
            return {0};
        }
        vector<int> ans(totalNodes(head), 0);

        int len = totalNodes(head);
        stack<pair<ListNode*, int>> st;
        st.push({head, 0});
        ListNode* currNode = head->next;

        for(int i=1; i<len; i++){
            if(currNode->val <= st.top().first->val){
                st.push({currNode, i});
            } else{
                while(!st.empty() && st.top().first->val < currNode->val){
                    ans[st.top().second] = st.top().first->val;
                    st.pop();
                }
                st.push({currNode, i});
            }
            currNode = currNode->next;
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