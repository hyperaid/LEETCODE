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
    bool solve(TreeNode* root, int k,map<int,int>&mpp){
        if(root==NULL) return false;
        if(mpp[k-root->val]){
            mpp[root->val]++;
            return true;
        }
        mpp[root->val]++;
        bool left=solve(root->left,k,mpp);
        bool right=solve(root->right,k,mpp);
        return left||right;

    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int>mpp;
        return solve(root,k,mpp);
    }
};