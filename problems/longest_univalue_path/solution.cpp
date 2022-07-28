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
    int dfs(TreeNode* root, int data) {
        if(!root) return 0;
        if(root->val != data) return 0;
        return 1 + max(dfs(root->left, data), dfs(root->right,data));
        
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int l = dfs(root->left, root->val);
        int r = dfs(root->right, root->val);
        return max(l+r, max(longestUnivaluePath(root->left),longestUnivaluePath(root->right)));
    }
};