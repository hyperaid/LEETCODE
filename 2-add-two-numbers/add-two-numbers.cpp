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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // long long combined=0;
        // long long i=0;
        // while(l1!=NULL){
        //     combined=combined*10 + l1->val;
        //     l1=l1->next;
        // }
        // long long rev_num=0;
        // while (combined > 0) {
        //     rev_num = rev_num * 10 + combined % 10;
        //     combined = combined / 10;
        // }
        // cout<<combined<<endl;
        // long long combined1=0;
        // // i=
        // while(l2!=NULL){
        //     combined1=combined1*10 + l2->val;
        //     l2=l2->next;
        // }
        // long long rev_num1=0;
        //  while (combined1 > 0) {
        //     rev_num1 = rev_num1 * 10 + combined1 % 10;
        //     combined1 = combined1 / 10;
        // }
 
        // long long combined_sum=rev_num1+rev_num;
        // cout<<combined_sum<<endl;

 
        // long long digit= combined_sum % 10;


        //     ListNode* ans1=new ListNode(digit);
        
        //     ListNode* ans=ans1;
        //     combined_sum/=10;
        //     cout<<digit<<endl;



         
        // while(combined_sum != 0) {
        //     digit = combined_sum % 10;
        //     ans->next=new ListNode(digit);
        //     cout<<digit<<endl;
        //     ans=ans->next;  // Extract the last digit
         
        //         combined_sum /= 10;  // Remove the last digit
        // }
        // return ans1;

      
        ListNode*ans=new ListNode(0);
        ListNode *p=l1,*q=l2,*curr=ans;
        int carry=0;
        while(p!=NULL || q!=NULL){
            int x= (p!=NULL)? p->val:0;
            int y= ( q!=NULL)? q->val:0;
            int sum=carry+x+y;
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            
            if(p!=NULL) p=p->next;
            if(q!=NULL) q=q->next;


        } 
        if(carry>0){
            curr->next=new ListNode(carry);
        }
        return ans->next;


    }
};