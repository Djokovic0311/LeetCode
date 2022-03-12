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
    bool isSymmetricTest(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) 
            return true; 
        
        else if(p == NULL || q == NULL) 
            return false; 
        
        else if(p->val!=q->val) 
            return false;
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricTest(root->right, root->left);
    }
};