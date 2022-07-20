#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseBetween(ListNode* A, int B, int C) {
    if(!A || !A->next) return A;
    ListNode* temp = A;
    
   vector<int> vec;
   
   while(temp){
       vec.push_back(temp->val);
       temp = temp->next;
   }
   
   for(int i=B-1; i<=(B-1)+abs(B-C)/2; i++){
    swap(vec[i], vec[((B-1)+abs(B-C)/2)-i]);
    //    int t = vec[i];
    //    vec[i] = vec[B+abs(B-C)-i];
    //    vec[abs(B-C)-i] = t;
   }
   for(int i=0; i<vec.size(); i++){
    cout<<vec[i]<<" ";
   }
   
   ListNode* res, *tempp;
   for(int i=0; i<vec.size(); i++){
       if(!res){
           res = new ListNode(vec[i]);
           tempp = res;
       }
       else{
           tempp->next = new ListNode(vec[i]);
           tempp = tempp->next;
       }
   }
   return res;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode* rev = reverseBetween(head, 2, 3);

    return 0;
}