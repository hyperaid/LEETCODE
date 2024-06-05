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
    int solve(TreeNode*root, int& ans,int& mini){
        if(root==NULL){
            return 0;
        }
        int left=root->val+solve(root->left,ans,mini);
        int right=root->val+solve(root->right,ans,mini);
         ans=max({ans,left+right-root->val,left,right,root->val});
        return max({left,right,root->val});
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int mini=INT_MIN;
        solve(root,ans,mini);
         
        return ans;
    }
};