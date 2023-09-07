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
    vector<ListNode*> reverse(ListNode* head,int l,int r){
        ListNode* prev=NULL, *cur=head;
        while(l<=r){
            ListNode* nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            l++;
        }
        return {head,prev,cur};
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode* prev=NULL,*cur=head;

        while(cur && i<left){
            prev=cur;
            cur=cur->next;
            i++;
        }
        // cout<<cur->val<<" ";
        auto it=reverse(cur,left,right);
        if(prev)
        prev->next=it[1];
        else head=it[1];
        it[0]->next=it[2];

        return head;
    }
};