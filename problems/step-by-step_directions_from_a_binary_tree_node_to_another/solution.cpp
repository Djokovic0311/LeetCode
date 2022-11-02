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
    bool find(TreeNode* root, int val, string& path) {
        if(root->val == val)
            return true;
        if(root->right && find(root->right, val, path))
            path += 'R';
        else if(root->left && find(root->left, val, path))
            path += 'L';
        return !path.empty();
        
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string sp, dp;
        find(root, startValue, sp);
        find(root, destValue, dp);
        while (!sp.empty() && !dp.empty() && sp.back() == dp.back()) {
        sp.pop_back();
        dp.pop_back();
        }
        return string(sp.size(), 'U') + string(rbegin(dp), rend(dp));
    }
};