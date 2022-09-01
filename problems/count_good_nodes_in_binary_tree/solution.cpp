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
    
    
    void helper(TreeNode* node, int& sum, int root){
        if(!node)
            return;
        if(node->val >= root) {
            sum++;
            root = node->val;
        }
        helper(node->left, sum, root);
        helper(node->right, sum, root);
        
    };
    
    int goodNodes(TreeNode* root) {
        
        int sum = 0;
        helper(root, sum, root->val);
       
        return sum;
    }
};