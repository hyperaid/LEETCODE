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
    static bool comparator(pair<int,string>&a,pair<int,string>&b){
        return a.second<b.second;
    }
    void dfs(TreeNode*root,string s,vector<string>&v1){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            // sum+=root->val;
            s=s+(char)(root->val+97);
            cout<<s<<endl;
            string a=s;
            reverse(a.begin(),a.end());
            v1.push_back(a);
            return;
        }
        dfs(root->left,s+(char)(root->val+97),v1);
        dfs(root->right,s+(char)(root->val+97),v1);

    }
    string smallestFromLeaf(TreeNode* root) {
        int sum=0;
        string s="";
        vector<string>v1;
        dfs(root,s,v1);
        sort(v1.begin(),v1.end());
        string a=v1[0];
        // reverse(a.begin(),a.end());
         
        return a;
    }
};