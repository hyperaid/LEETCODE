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
TreeNode* solve(TreeNode*root,int k){
        if(!root) return root;
        root->left=solve(root->left,k);
        root->right=solve(root->right,k);
        if(root->left==NULL and root->right==NULL and root->val==k){
            return NULL;
        }
        return root;
     
}
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
 
        return solve(root,target);
 
    }
};