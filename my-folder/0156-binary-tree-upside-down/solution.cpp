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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        TreeNode* cur_left = root->left;
        TreeNode* cur_right = root->right;
        TreeNode* new_root = upsideDownBinaryTree(root->left);
        cur_left->right = root;
        cur_left->left = cur_right;
        root->left = NULL;
        root->right = NULL;
        return new_root;        
    }
};
