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
    void sum(TreeNode* root, int tmp, int& ans) {
        if(root == NULL) return;

        tmp = tmp * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            ans += tmp;
        }
        sum(root->left, tmp, ans);
        sum(root->right, tmp, ans);
        
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        sum(root, 0, ans);
        return ans;
    }
};
