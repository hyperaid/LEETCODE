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
    TreeNode* solve(vector<int>& a,int& i,int bound){
        if(i==a.size() || a[i]>bound) return NULL;
        TreeNode*ab=new TreeNode(a[i++]);
        ab->left=solve(a,i,ab->val);
        ab->right=solve(a,i,bound);
        return ab;

    }
    TreeNode* bstFromPreorder(vector<int>& a) {
        int i=0;
        return solve(a,i,INT_MAX);

    }
};