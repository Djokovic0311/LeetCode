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
    int ans = 1;
    void dfs(TreeNode* root, int len) {
        if(!root) return;
        if(root->left){
            if(root->left->val == root->val + 1) {
                ans = max(ans, len+1);
                dfs(root->left, len+1);
            }
            else {
                dfs(root->left, 1);
            }
        }
        if(root->right) {
            if(root->right->val == root->val + 1) {
                ans = max(ans, len+1);
                dfs(root->right, len+1);
            }
            else {
                dfs(root->right, 1);
            }            
        }
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
};
