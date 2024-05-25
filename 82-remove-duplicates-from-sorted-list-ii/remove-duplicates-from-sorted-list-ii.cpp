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
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        ListNode* prev = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                int duplicateVal = head->val;
                while (head && head->val == duplicateVal) {
                    head = head->next;
                }
                prev->next = head;
            } else {
                prev = prev->next;
                head = head->next;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
