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
    vector<TreeNode*>inorder;
    void traversal(TreeNode*root){
        if(root==NULL) return;
        traversal(root->left);
        inorder.push_back(root);
        traversal(root->right);

    }
    TreeNode* make(int i,int j){
        if(i>j) return nullptr;
        int mid=i+(j-i)/2;
        TreeNode*root=new TreeNode(inorder[mid]->val);
        root->left=make(i,mid-1);
        root->right=make(mid+1,j);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        traversal(root);
        TreeNode*head=make(0,inorder.size()-1);
        return head;
    }
};