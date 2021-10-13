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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0) return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        if(n == 1) return root;
        vector<int> left;
        vector<int> right;
        for(int i = 1; i < n; i++) {
            if(preorder[0] > preorder[i]) left.push_back(preorder[i]);
            else right.push_back(preorder[i]);
            
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};