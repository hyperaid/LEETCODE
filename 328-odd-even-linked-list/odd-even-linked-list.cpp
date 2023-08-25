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
    // listNode* deleteNext(ListNode*pre){
    //     ListNode * temp=pre
    // }
    ListNode* oddEvenList(ListNode* head) {
        ListNode* headOdd=NULL,*headEven=NULL,*tailOdd=NULL,*tailEven=NULL;
        int count=1;
        if(head==NULL) return NULL;
        else if(head->next==NULL) return head;
        // headOdd=head->next;
        // headOdd->next=tailOdd;

        // headEven=head->next->next;
        // headEven->next=tailEven;
        while(head!=NULL){
            // head=head->next;
            if(count%2!=0){
                if(headOdd==NULL){
                    headOdd=tailOdd=head;
                    head=head->next;
                }
                else{
                    tailOdd->next=head;
                    tailOdd=tailOdd->next;
                    head=head->next;
                }
            
            }
            else{
                if(headEven==NULL){
                    headEven=tailEven=head;
                    head=head->next;
                }
                else{
                    tailEven->next=head;
                    tailEven=tailEven->next;
                    head=head->next;

                }
            }
            count++;
            // head=head->next;

        }
        // if(head)
        tailEven->next=NULL;
        tailOdd->next=headEven;
        return headOdd;
    

    }
};