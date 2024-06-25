// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         int count=0;
//         if(head==NULL) return NULL;
//         if(head->next==NULL || k==0) return head;
//         ListNode* temp=head;
//         while(head){
//             head=head->next;
//             count++;

//         }
//         // cout<<count<<endl;
//         k=k%count;
        
//         head=temp;
//         while(k-- && temp){
//             temp=temp->next;
//         }
//         // cout<<temp->val;
//          ListNode* ne=temp->next;
//          ListNode*temp1=ne;
//          temp->next=NULL;

//          while(ne->next!=NULL){
//             ne=ne->next;
//          }
//          cout<<ne->val<<endl;
//          ne->next=head;
//         //  temp->next=NULL;
//          return temp1;

        

//     }
// };
// 
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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=0;
        if(head==NULL) return NULL;
        if(head->next==NULL || k==0) return head;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            count++;

        }
        // cout<<count<<endl;
        k=k%count; 
         if(k==0) return head;
        count=count-k;
         
        ListNode*curr=head,*prev=NULL;
        while(count-- ){
            prev=curr;
            curr=curr->next;
        }
        // cout<<temp->val;
         prev->next=NULL;
         ListNode* tail=curr;
         while(tail->next!=NULL){
            tail=tail->next;
         }
         tail->next=head;
         head=curr; 
         return head;
    }
};