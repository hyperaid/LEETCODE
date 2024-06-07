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
class BSTIterator {
private: stack<TreeNode*>s;
public:
    BSTIterator(TreeNode* root) {
        pushall(root);
        
    }
    
    int next() {
        if(s.top()){
            TreeNode*a=s.top();
            s.pop();
            pushall(a->right);
            
             return a->val;
        }
        else{
            return 0;
        }
    }
    
    bool hasNext() {
        if(!s.empty()) return true;
        return false;
    }
    private:
    void pushall(TreeNode*root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */