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
    vector<vector<int>> res;
    void path(int target, vector<int> tmp, TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right && root->val == target) {
            tmp.push_back(root->val);
            res.push_back(tmp);
            return;
        }
        tmp.push_back(root->val);
        path(target - root->val, tmp, root->left);
        path(target - root->val, tmp, root->right);
            
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        path(targetSum, tmp, root);
        return res;
    }
};
