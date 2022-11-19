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
    void dfs(TreeNode* root, long long sum) {
        if(!root) return;
        if(root->val == sum) res++;
        dfs(root->left, sum-root->val);
        dfs(root->right, sum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root) {
            dfs(root, (long long)targetSum);
            pathSum(root->right, targetSum);
            pathSum(root->left, targetSum);
        }
        return res;
    }
};