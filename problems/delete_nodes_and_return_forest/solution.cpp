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
    vector<TreeNode*> result;
    set<int> to_delete;
    TreeNode* dfs(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& result, bool isroot) {
        if(!root) return NULL;
        bool deleted = false;
        for(int i : to_delete)
            if(i == root->val)
                deleted = true;
        if(isroot && !deleted) result.push_back(root);
        root->left = dfs(root->left, to_delete, result, deleted);
        root->right = dfs(root->right, to_delete, result,deleted);
        return deleted? NULL : root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        dfs(root, to_delete, result, true);
        return result;
    }
};