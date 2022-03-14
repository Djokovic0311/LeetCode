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
    void dfs(TreeNode* root,int &ans,TreeNode* &prev){
        if(root==NULL)return;
        dfs(root->left,ans,prev);
        if(prev!=NULL)ans=min(ans,root->val-prev->val);
        prev=root;
        dfs(root->right,ans,prev);
    }    
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev=NULL;
        int res = INT_MAX;

        dfs(root,res,prev);
        return res;
    }
};