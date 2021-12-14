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
    int sum = 0;
    int inorder(TreeNode* root, int L, int R) {
        if(root) {
            inorder(root->left, L, R);
            if(root->val >= L && root->val <= R) sum += root->val;
            inorder(root->right, L, R);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return inorder(root, low, high);
    }
};