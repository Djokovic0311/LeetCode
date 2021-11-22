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
    int findminfromright(TreeNode* root){
        while(root->left!=nullptr)
            root=root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else {
            if(root->right == NULL) return root->left;
            else if(root->left == NULL) return root->right;
            else {
                root->val = findminfromright(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};