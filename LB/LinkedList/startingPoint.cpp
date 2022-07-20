#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};


class Solution {
    public:
    map<Node*, bool> mp;
    Node* getHeadOfLoop(Node* head){
        Node* temp = head;
        while(temp){
            mp[temp] = true;
            if(mp.count(temp->next) != 0){
                return temp->next;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // apply floyd-warshall algo and then when slow == fast then do slow = head and then move both of them one by one and then when slow == fast return....
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node* head = new Node(1);
    Node* t = head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = t;

    Solution s;
    Node* ans = s.getHeadOfLoop(head);
    cout<<ans->data<<"\n";
    
    return 0;
}