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
    int rob(TreeNode* root) {
        int max_include_root = 0;
        int max_donnot_include_root = 0;
        return dfs(root, max_include_root, max_donnot_include_root);
    }
    
    int dfs(TreeNode* root, int& max_include_root, int& max_donnot_include_root) {
        if (root == NULL) {
            max_include_root = 0;
            max_donnot_include_root = 0;
            return 0;
        }
        int max_donnot_include_root_left = 0;
        int max_donnot_include_root_right = 0;

        int max_include_root_left = 0;
        int max_include_root_right = 0;

        int max_left = dfs(root->left, max_include_root_left, max_donnot_include_root_left);
        int max_right = dfs(root->right, max_include_root_right, max_donnot_include_root_right);

        max_include_root = root->val + max_donnot_include_root_left + max_donnot_include_root_right;
        max_donnot_include_root = max_left + max_right;

        return max(max_include_root, max_donnot_include_root);
    }
};
