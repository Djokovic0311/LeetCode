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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        int level = 1;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> tmp;
            for(int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                tmp.push_back(node->val);
            }
            if(level % 2 == 0)
                reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            level++;
        }
        return res;
    }
};
