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
    ListNode* reverse(ListNode*a){
        ListNode*prev=nullptr;
        ListNode*curr=a;
        while(curr){
            ListNode*temp=curr->next;
             curr->next=prev;
             prev=curr;
             curr=temp;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode*fast=head;
        ListNode*slow=head;
        int count=0;
        while(slow!=NULL && fast!=NULL &&fast->next!=NULL){
            // count+=2;
            slow=slow->next;
            fast=fast->next->next;
        }
       
        ListNode*b=reverse(slow);
        slow=head;
        // fast=head;
      
        while(b){
            if(slow->val!=b->val) return false;
            slow=slow->next;
            b=b->next;
        }
        return true;



    }
};
