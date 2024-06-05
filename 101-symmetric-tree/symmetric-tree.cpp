/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode*r1,TreeNode*r2){
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL ||r2==NULL) return false;
        if(r1->val!=r2->val) return false;
        bool left=solve(r1->left,r2->right);
        bool right=solve(r1->right,r2->left);
        return left&& right;

    }
    bool isSymmetric(TreeNode* root) {
        bool a= solve(root->left,root->right);
        return a;
    }
};