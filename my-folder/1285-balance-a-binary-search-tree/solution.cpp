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
    vector<TreeNode*> inordered;
    void inorder(TreeNode* root) {
        if(root->left) inorder(root->left);
        inordered.push_back(root);
        if(root->right) inorder(root->right);
    }
    TreeNode* buildTree(int start, int end) {
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* root = inordered[mid];
        root->left = buildTree(start, mid-1);
        root->right = buildTree(mid+1, end);
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int start = 0, end = inordered.size()-1;
        return buildTree(start,end);
    }
};
