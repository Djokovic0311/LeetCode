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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> bounds;
        if (root) {
            bounds.push_back(root->val);
            getBounds(root->left, bounds, true, false);
            getBounds(root->right, bounds, false, true);
        }
        return bounds;
    }

private:
    void getBounds(TreeNode* node, vector<int>& res, bool lb, bool rb) {
        if (!node)  return;
        if (lb) res.push_back(node->val);
        if (!lb && !rb && !node->left && !node->right)  res.push_back(node->val);
        getBounds(node->left, res, lb, rb && !node->right);
        getBounds(node->right, res, lb && !node->left, rb);
        if (rb) res.push_back(node->val);
    }
};
