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
    ListNode* swapPairs(ListNode* A) {
        if (A == NULL) {
            return NULL;
        }
        ListNode* temp = new ListNode(-1);
        ListNode* prev = temp;
        temp->next = A;

        while (A!=NULL && A->next != NULL) {
            ListNode* b = A->next;
            A->next = A->next->next;
            prev->next = b;
            b->next = A;
            prev = A;
            A=A->next;
        }
        return temp->next;
    }
};