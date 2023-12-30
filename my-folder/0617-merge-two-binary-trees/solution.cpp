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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2) {
            TreeNode* node = new TreeNode(root1->val + root2->val);
            node->right = mergeTrees(root1->right, root2->right);
            node->left = mergeTrees(root1->left, root2->left);
            return node;
        } else {
            return root1 ? root1 : root2;
        }
    }
};
