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
    int depth(TreeNode* root) {
        if(!root) return 0;
        return 1+ max(depth(root->right), depth(root->left));
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int l = depth(root->left), r = depth(root->right);
        return l == r ?  root : (l > r ?  subtreeWithAllDeepest(root->left) : subtreeWithAllDeepest(root->right));
    }
};
