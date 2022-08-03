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
    void fillMap(ListNode* head, int x, map<string, vector<int>> &mp){
        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                mp["LESS"].push_back(temp->val);
            }
            else{
                mp["MORE"].push_back(temp->val);
            }
            temp = temp->next;
        }
    }

    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        map<string, vector<int>> mp;
        ListNode* temp = head;
        ListNode* temp2 = head;
        
        fillMap(temp, x, mp);
        
        for(int i=0; i<mp["LESS"].size(); i++){
            temp2->val = mp["LESS"][i];
            temp2 = temp2->next;
        }

        for(int j=0; j<mp["MORE"].size(); j++){
            temp2->val = mp["MORE"][j];
            temp2 = temp2->next;
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