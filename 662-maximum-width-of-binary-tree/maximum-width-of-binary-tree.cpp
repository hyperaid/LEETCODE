/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int mini,maxi;
        int ans=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            int minii=q.front().second;
            for (int i = 0; i < n; i++) {
                auto a = q.front();
                TreeNode* b = a.first;
                int level = a.second;
                int curindex=level-minii;
                q.pop();
                if(i==0) mini=curindex;
                if(i==n-1) maxi=curindex;
                if(b->left){
                    q.push({b->left,(long long)2*level+1});
                }
                if(b->right){
                    q.push({b->right,(long long)2*level+2});

                }
             
            }
            ans=max(ans,maxi-mini+1);
          
                
            
        }
        return ans;
    }
};