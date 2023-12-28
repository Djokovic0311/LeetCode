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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;

    }
    int helper(TreeNode* node) {
        if(!node) return 0;
        int left_max = max(helper(node->left), 0);
        int right_max = max(helper(node->right), 0);
        res = max(res, left_max + right_max + node->val);
        return max(left_max, right_max) + node->val;
    }
};
