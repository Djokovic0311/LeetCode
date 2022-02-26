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
    void traverse(TreeNode* root, string &res){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        if(root->left == NULL && root->right!=NULL){
            res+="()";
        }
        if(root->left){
            res+="(" + to_string(root->left->val);
            traverse(root->left,res);
            res.push_back(')');
        }
        if(root->right){
            res+="(" + to_string(root->right->val);
            traverse(root->right,res);
            res.push_back(')');
        } 
        return;            
    }
    string tree2str(TreeNode* root) {
        string res = "";
        res+=to_string(root->val);
        traverse(root,res);
        return res;
    }
};
