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
    int height(TreeNode* root, int val, int h) {
        if(!root) return 0;
        if(root->val == val)
            return h;
        int l = height(root->left, val, h+1);
        int r = height(root->right, val, h+1);
        return max(l, r);
    }
    TreeNode* lca(TreeNode* root, int p, int q) {
        if(!root)
            return root;
        if(root->val == p || root->val == q)
            return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if (left!=NULL && right!=NULL) return root;
        
        if (left!=NULL && right==NULL) return left;
        
        return right;
    }
    int findDistance(TreeNode* root, int p, int q) {
        // cout << height(root,5,0);
        TreeNode* LCA = lca(root, p, q);

        return height(LCA, p,0) + height(LCA, q,0);
    }
};
