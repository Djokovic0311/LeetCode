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
    int res = 0;
    // maxValue, minValue, size
    vector<int> helper(TreeNode* root) {
        if(!root) return {};
        auto lv = helper(root->left);
        auto rv = helper(root->right);
        vector<int> tmp{root->val,root->val,1};
        if(lv.size()) {
            if(lv[0] < root->val) {
                tmp[2] += lv[2];
                tmp[1] = lv[1];
            } else {
                tmp = {INT_MAX, INT_MIN, 0};
                return tmp;
            }
        }
        if(rv.size()) {
            if(rv[1] > root->val) {
                tmp[2] += rv[2];
                tmp[0] = rv[0];
            } else {
                tmp = {INT_MAX, INT_MIN, 0};
                return tmp;
            }
        }
        res = max(res, tmp[2]);
        return tmp;
    }
    int largestBSTSubtree(TreeNode* root) {
        helper(root);
        return res;
    }
};
