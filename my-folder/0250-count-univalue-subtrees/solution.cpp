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
    int count = 0;
    bool isUnival(TreeNode* root) {
        if(!root) return true;
        bool left = isUnival(root->left);
        bool right = isUnival(root->right);
        if(left && right) {
            if(root->left && root->left->val != root->val) return false;
            if(root->right && root->right->val != root->val) return false;
            count++;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        isUnival(root);
        return count;
    }
};
