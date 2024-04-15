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
    void call(TreeNode* root, string a,vector<string>&v1){
        if(root==NULL){
            // cout<<"pahle"<<a<<endl;

            
            return ;

        }
        a+=to_string(root->val);
        // cout<<"pahle"<<a<<endl;
        if(!root->left and !root->right) v1.push_back(a);
        call(root->left,a,v1);
        // a.pop_back();
        call(root->right,a,v1);
        
        // cout<<"after left"<<a<<endl;
         a.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string a="";
        vector<string>v1;
        call(root,a,v1);
        int sum=0;
        for(int i=0;i<v1.size();i++){
            sum+=stoi(v1[i]);
        }
        return sum; 
    }
};