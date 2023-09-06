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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }

        int x=(count/k);
        if(count%k) x++;
        // cout<<c<<" ";
        
        ListNode* t1=head,*t2=head;
        vector<ListNode*> ans;
        while(t1){
            count--;
            x--;
            if(x==0){
                if(!t1 || ans.size()==k-1){
                    ans.push_back(t2);
                    break;
                }
                ListNode* t3=t1->next;
                t1->next=NULL;
                ans.push_back(t2);
                t1=t3;
                t2=t3;
                x=(count/(k-ans.size()));
                if(count%(k-ans.size())) x++;
            }
            else t1=t1->next;
            // cout<<k<<" ";
        }

        while(ans.size()<k){
            ans.push_back(NULL);
        }
        return ans;
    }
};