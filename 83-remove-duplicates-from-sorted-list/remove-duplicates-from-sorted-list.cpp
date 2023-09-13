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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr; // Handle the case of an empty list.
        }
        ListNode *temp=head;
        while(temp->next && temp){
                        cout << "temp: " << temp->val << ", temp->next: " << temp->next->val << endl;

            // if(temp->next==NULL){
            //     return head;
            // }
            
            if(temp->val==temp->next->val){
                temp->next=temp->next->next;
                continue;
            }
            temp=temp->next;
        }
        return head;
    }
};