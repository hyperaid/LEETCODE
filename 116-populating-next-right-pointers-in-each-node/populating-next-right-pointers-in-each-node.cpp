/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                // if(i==n-1){
                //     q.front()
                // }
                if (i == n - 1) {
                    Node* a = q.front();
                    q.pop();
                    a->next = NULL;
                    if (a->left)
                        q.push(a->left);
                    if (a->right)
                        q.push(a->right);
                } else {
                    Node* a = q.front();
                    q.pop();
                    a->next = q.front();
                    if (a->left)
                        q.push(a->left);
                    if (a->right)
                        q.push(a->right);
                }
            }
        }
        return root;
    }
};