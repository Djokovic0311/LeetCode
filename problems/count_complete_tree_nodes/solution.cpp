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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;                           //Base Case
        
        int leftHeight = 0, rightHeight = 0;    // Define left and right Height as 0 if not found

        if(root->left) leftHeight = countNodes(root->left);     //Make left call and traverse till left node edge exists
        if(root->right) rightHeight = countNodes(root->right);  //Make right call and traverse till right node edge exists.
        
        // cout<<1 + leftHeight + rightHeight<<" ";
        
        return 1 + leftHeight + rightHeight;   
    }
};