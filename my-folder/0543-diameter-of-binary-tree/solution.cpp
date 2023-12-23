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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        longestPath(root);
        return res;
    }

    int longestPath(TreeNode* node) {
        if(node == NULL) return 0;
        int left = longestPath(node->left);
        int right = longestPath(node->right);
        res = max(res, left+right);
        return max(left, right)+1;
    }
};
