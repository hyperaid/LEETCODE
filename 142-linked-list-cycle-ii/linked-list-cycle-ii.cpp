/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL ) return nullptr;
        ListNode*temp=head;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            // parent=slow;
            slow=slow->next;
            fast=fast->next->next;
            // cout<<parent->val<<"  "<<slow->val<<"  "<<fast->val<<endl;
            if(slow==fast){
                // cout<<parent->val;
                break;
            }
        }
        if(fast==NULL || fast->next==NULL) return NULL;

        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
            if(temp==slow) break;
        }



        return temp;
    }
};