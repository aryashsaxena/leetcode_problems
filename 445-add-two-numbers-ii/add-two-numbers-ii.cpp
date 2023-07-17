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
    ListNode* reverse(ListNode* node){
        ListNode* prev=NULL,*cur=node;

        while(cur){
            ListNode* nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2 ) return l1;
        if(!l1 ) return l2;
        if(!l2) return l1;

        l1=reverse(l1);
        l2=reverse(l2);

        int c=0;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;

        while(l1 || l2 || c){
            int sum=0;

            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }

            sum+=c;
            temp->next=new ListNode( sum%10);
            c=sum/10;
            temp=temp->next;
        }
        ans=reverse(ans->next);
        return ans;
    }
};