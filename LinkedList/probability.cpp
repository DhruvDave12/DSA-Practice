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
    // ListNode* commonHead;
    // int N;
    // int total_calls = 0;
    vector<int> v;
    Solution(ListNode* head) {
        // commonHead = head;

        // int temp = 0;
        // ListNode* nodeTemp = head;
        // while(nodeTemp){
        //     temp++;
        //     nodeTemp = nodeTemp->next;
        // }
        // N = temp;

        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
    }

    int getRandom() {
        // total_calls++;
        // ListNode* temp = commonHead;
        // int nodeToReturn = total_calls % N;
        // int x = 0;
        // while(temp){
        //     if(x == nodeToReturn){
        //         return temp->val;
        //     }
        //     temp = temp->next;
        //     x++;
        // }   

        int x = rand()%v.size();
        return v[x];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}