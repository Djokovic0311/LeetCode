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
    int getDepth(TreeNode *root) {
        return root ? 1 + max(getDepth(root->left), getDepth(root->right)) : 0;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int l = getDepth(root->left), r = getDepth(root->right);
        return l == r ? root : subtreeWithAllDeepest(l > r ? root->left : root->right);
    }
};
