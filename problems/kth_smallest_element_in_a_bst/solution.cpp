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
    void preorder(TreeNode* root, vector<int>& res) {
        if(root) {
            if(root->left) {
                preorder(root->left, res);
            }
            res.push_back(root->val);
            if(root->right) {
                preorder(root->right, res);
            }                
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        preorder(root, res);
        return res[k-1];
    }
};