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
    ListNode* reverse(ListNode* head){
        ListNode* cur=head,*prev=NULL;
        while(cur){
            ListNode* nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* temp=head;
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* l1=temp, *l2=slow->next;
        slow->next=NULL;

        l2=reverse(l2);
        head=l1;
        int f=0;
        ListNode* i=l1,*j=l2;
        while(l1 && l2){
            if(f==0){
                ListNode* nxt=l1->next;
                 l1->next=l2;
                 l1=nxt;
                 f=1;
            }
            else{
                ListNode* nxt=l2->next;
                l2->next=l1;
                l2=nxt;
                f=0;
            }
        }
        
    }
};