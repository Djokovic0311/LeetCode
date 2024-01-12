/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        if(root==p || root==q) return root;
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if(left && right) return root;
        if(left==NULL and right==NULL) return NULL;
        return left!=NULL? left : right;        
    }
};
