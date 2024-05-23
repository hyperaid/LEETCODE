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
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        ListNode*front=head;
        ListNode*back=head;
        while(head){
            head=head->next;
            len++;
        }
        int end=len-k;
        int a=1;
        while(a!=k){
            front=front->next;
            a++;
        }
       while(end--){
        back=back->next;
       }
       a=front->val;
       front->val=back->val;
       back->val=a;
       
        return temp;
        
        
    }
};