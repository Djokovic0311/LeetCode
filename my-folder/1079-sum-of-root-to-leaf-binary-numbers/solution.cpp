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
    int func(TreeNode* root, int sum) {
        if(!root) return 0;
        sum = (2 * sum) + root->val;
        if(!root->left && !root->right) return sum;
        return func(root->left, sum) + func(root->right, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        return func(root, 0);
    }
};
