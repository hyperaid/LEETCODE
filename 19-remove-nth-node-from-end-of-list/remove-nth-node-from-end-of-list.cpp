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
        // ListNode* temp=head;
        // ListNode* temp1=head;
        // if(temp->next==NULL) return NULL;
        // int count=1;
        // while(temp->next->next!=NULL){
        //     temp=temp->next;
        //     count++;
        //     // cout<<count<<endl;
        // }
        // int del=count-n+1;
        // int countt=1;
        // if((count+1)==n){ 
        //     head=head->next;
            
        //     return head;}
        // if(n==1){
        //     temp->next=NULL;
        //     return head;
        // }
        // else {
        //     while(countt!=del){
        //         temp1=temp1->next;
        //          countt++;

        //     }
        //     temp1->next=temp1->next->next;
        //     return head;
        // }
        //  ListNode* start = new ListNode();
        // start -> next = head;
        // ListNode* fast=start;
        // ListNode* slow= start;
        // for(int i=0;i<n;i++){
        //     fast=fast->next;
        // }
        // // if(head==NULL && n==1){
        // //     return NULL;
        // // }
        // while(fast->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next;

        // }
        // slow->next=slow->next->next;
        // return start->next;
        ListNode *slow=head, *fast=head;

        for(int i=0; i<n; i++)
            fast = fast->next;

        if(!fast)
        {
            head = head->next;
            delete slow;    // Since slow points to the first node
            return head;
        }
        
        while(fast && fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if(slow && slow->next)
        {
            // ListNode* temp = slow->next;
            slow->next = slow->next->next;
            // delete temp;
        }

        return head;
       
        
        

    }

};