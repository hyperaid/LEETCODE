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
        ListNode* temp=head;
        ListNode* temp1=head;
        if(temp->next==NULL) return NULL;
        int count=1;
        while(temp->next->next!=NULL){
            temp=temp->next;
            count++;
            // cout<<count<<endl;
        }
        int del=count-n+1;
        int countt=1;
        if((count+1)==n){ 
            head=head->next;
            
            return head;}
        if(n==1){
            temp->next=NULL;
            return head;
        }
        else {
            while(countt!=del){
                temp1=temp1->next;
                 countt++;

            }
            temp1->next=temp1->next->next;
            return head;
        }
        // cout<<count<<endl;
        // if(n==1)
        // while(cc!=(count-n)){
        //     cc++;
        //     // temp1=temp1->next;

            
        // }
        // if(temp1->next==NULL){
            
        // }
        // temp1->next=temp1-next->next;
        // return head;

    }

};