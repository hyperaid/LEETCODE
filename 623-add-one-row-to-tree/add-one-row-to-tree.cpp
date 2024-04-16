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
    void dfs(TreeNode* root, int val, int d,int dp){
        if(root==NULL){
            return ;
        }
        if(dp==(d-1)){
            cout<<1<<endl;
            TreeNode*a=root->left;
            TreeNode*b=root->right;
            TreeNode*ab=new TreeNode(val);
            root->left=ab;
            root->right=new TreeNode(val);
            root->left->left=a;
            root->right->right=b;
            return;
            
        }
        dfs(root->left,val,d,dp+1);
        dfs(root->right,val,d,dp+1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        dfs(root,val,depth,1);
        return root;
    }
};