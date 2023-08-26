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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> m1;
        while(headA!=NULL){
            m1[headA]++;
            headA=headA->next;
        }
        while(headB!=NULL){
            if(m1[headB]){
                return headB;
            }
            // m1[headB]++;
            headB=headB->next;

        }
        return NULL;
    }
};