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
    int closestValue(TreeNode* root, double target) {
        int result=root->val;
        while(root){
            if((double)root->val==target)return root->val;
            if(abs((double)root->val-target)<abs(result-target))
                result=root->val;
            if(root->val>target)root=root->left;
            else root=root->right;
        }
        return result;        
    }
};
