#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:

    void helper(Node* head, Node* res){
        if(!head) return;

        cout<<head->val<<"->";
        helper(head->next, res->next);
        helper(head->child, res->next);
    }

    Node* flatten(Node* head) {
        Node* res;
        Node* temp = head;
        helper(temp, res);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}