/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;

        ListNode* h1=new ListNode(-1);
        ListNode* h2=new ListNode(-1);
        ListNode* t1=h1,* t2=h2;

        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                t1->next=new ListNode(temp->val);
                t1=t1->next;
            }
            else{
                t2->next=new ListNode(temp->val);
                t2=t2->next;
            }
            temp=temp->next;
        }
        
        if(!h2->next) return h1->next;
        if(!h1->next) return h2->next;
        
        t1->next=h2->next;
        return h1->next;
    }
};