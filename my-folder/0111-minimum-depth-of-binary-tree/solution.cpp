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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        // If left subtree is NULL, recur for right subtree
        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }

        // If right subtree is NULL, recur for left subtree
        if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }

        // If root has both left and right children, recur for both subtrees and take the minimum of two values
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
