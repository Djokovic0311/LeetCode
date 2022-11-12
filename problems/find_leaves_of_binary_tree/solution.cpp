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
    void dfs(vector<int>& cur, TreeNode*& root) {
        if(!root->left && !root->right) {
            cur.push_back(root->val);
            root = NULL;
        }
        else {
        if(root->left) dfs(cur,root->left);
        if(root->right) dfs(cur,root->right);            
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        
        while(root) {
            vector<int> l;
            dfs(l,root);
            res.push_back(l);
        }
        return res;
    }
};