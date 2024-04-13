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
class comp {
    public:
        bool operator()(const ListNode*a,const ListNode*b){
            return a->val>b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        int n=lists.size();
        ListNode*temp=new ListNode(-1);
        ListNode*head=temp;
        // if(lists==NULL) return NULL;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        while(!pq.empty()){
            ListNode*small=pq.top();
            pq.pop();
            head->next=small;
            head=head->next;
            if(small->next) pq.push(small->next);
        }
        return temp->next;
    }
};