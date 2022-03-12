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
    bool ans;
    int helper(TreeNode* root) {
        if(!root)
            return 0;
        if(!ans) 
            return 0;
        int leftSubTree = helper(root->left);
        int rightSubTree = helper(root->right);
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;}
        return 1 + max(leftSubTree, rightSubTree);
    
    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        int temp = helper(root);
        return ans;
    }
};
