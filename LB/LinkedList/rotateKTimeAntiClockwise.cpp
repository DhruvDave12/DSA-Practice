#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    struct ListNode* next;
    
    ListNode(int x){
        data = x;
        next = NULL;
    }
    
}; 

class Solution {
public:
    int getLen(ListNode* head){
        ListNode* temp = head;
        int counter = 0;
        while(temp){
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* temp3 = head;
        while(temp3->next){
            temp3 = temp3->next;
        }
        int len = getLen(temp2);
        k = k%len;
        int x = len - k;
        int c = 1;
        if(x == len) return head;
        while(c != x){
            c++;
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        temp3->next = head;
        
        return newHead;
        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}