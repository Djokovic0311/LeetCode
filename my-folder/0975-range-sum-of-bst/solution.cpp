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
    int preorder(TreeNode* root, int L, int R) {
        if(root) {
            if(root->val >= L && root->val <= R) sum += root->val;
            if(root->val > L)
                preorder(root->left, L, R);
            if(root->val < R)
                preorder(root->right, L, R);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return preorder(root, low, high);
    }
};
