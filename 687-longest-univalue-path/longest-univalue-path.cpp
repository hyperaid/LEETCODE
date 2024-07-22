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
    int solve(TreeNode*root,int &maxi){
        if(root==NULL) return 0;
        int left=solve(root->left,maxi);
        int right=solve(root->right,maxi);
        if(root->left==NULL || root->left->val!=root->val) left=0;
        if(root->right==NULL || root->right->val!=root->val) right=0;
        maxi=max(maxi,left+right);
        return 1+max(left,right);


    }
    int longestUnivaluePath(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
};