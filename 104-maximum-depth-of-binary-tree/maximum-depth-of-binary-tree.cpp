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
    void solve(int i,TreeNode*root,int &maxi){
        if(root==NULL){
            maxi=max(i,maxi);
            return ;
        }
        solve(i+1,root->left,maxi);
        solve(i+1,root->right,maxi);

    }
    int maxDepth(TreeNode* root) {
        int i=0;
        int maxi=0;
        solve(i,root,maxi);
        return maxi;

    }
};