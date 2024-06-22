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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        if(head==NULL) return head;
        ListNode* temp=new ListNode(1);
        temp->next=head;
        while(head){
            count++;
            head=head->next;
        }
        n=count-n;
        head=temp;
        for(int i=0;i<n;i++) head=head->next;
        head->next=head->next->next;

        cout<<count<<"  "<<n;
        // temp->next=temp->next->next;
        return temp->next;
    }
};