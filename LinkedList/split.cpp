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
    vector<ListNode*> v;
    
    int totalNodes (ListNode* head) {
        int temp = 0;
        ListNode* tempNode = head;
        while(tempNode){
            temp ++;
            tempNode = tempNode->next;
        }
        return temp;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int total = totalNodes(head);
        int rem = total % k;
        vector<ListNode*> ans(k, NULL);

        if(k >= total){
            // all gets only one node in it and others will be null
            ListNode* temp = head;
            int i = 0;
            while(temp){
                ListNode *toAttach = temp;
                temp = temp->next;
                toAttach->next = NULL;
                ans[i] = toAttach;
                i++;
            }
        }
        else{
            // else we give +1 rem times from start and then insert those many nodes
            ListNode* temp = head;
            vector<int> val (k, total/k);
            for(int i=0 ;i<rem; i++){
                val[i]++;
            }
            int ansIT = 0;
            int x = 0;
            ListNode* temp2;
            while(temp){
                while(x < val[ansIT]){
                    ListNode* toAttach = temp;
                    temp = temp->next;
                    
                    if(ans[ansIT] == NULL){
                        ans[ansIT] = toAttach;
                        temp2 = ans[ansIT];
                        temp2->next = NULL;
                    } else{
                        temp2->next = toAttach;
                        temp2 = temp2->next;
                    }
                }

                temp2->next = NULL;
                temp2 = NULL;
                x++;
                ansIT++;
            }
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