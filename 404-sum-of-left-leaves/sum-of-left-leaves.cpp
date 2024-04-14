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
    void leaf(TreeNode*root,int &sum){
        // int sum=0;

        if(root==NULL) return ;
        leaf(root->left,sum);
        if(root->left &&root->left->left==NULL && root->left->right==NULL) sum+=root->left->val;
        leaf(root->right,sum);




    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        leaf(root,sum);
        return sum;
    }
};