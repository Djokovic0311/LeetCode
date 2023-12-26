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
    bool isLeaf(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
    }
    void addLeaves(vector<int>& res, TreeNode* root) {
        if(isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if(root->left) addLeaves(res, root->left);
        if(root->right) addLeaves(res, root->right);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->val);
        TreeNode* node = root->left;
        while(node) {
            if(!isLeaf(node)) {
                res.push_back(node->val);
            }
            if(node->left) node = node->left;
            else node = node->right;
        }
        addLeaves(res, root);
        node = root->right;
        stack<int> stk;
        while(node) {
            if(!isLeaf(node)) {
                stk.push(node->val);
            }
            if(node->right) node = node->right;
            else node = node->left;
        }
        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
