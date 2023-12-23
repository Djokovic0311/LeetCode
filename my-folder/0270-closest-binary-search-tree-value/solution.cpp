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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        int val;
        while(root) {
            val = root->val;
            closest = abs(val-target) < abs(closest-target) || abs(val-target) == abs(closest - target) && val < closest ? val : closest;
            root = (target < root->val) ? root->left : root->right;
            
        }

        return closest;
    }
};
