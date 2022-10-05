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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, NULL);
        int len;
        queue<TreeNode*> q;
        q.push(root);
        while (--depth) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                if (depth > 1) {
                    if (q.front()->left) q.push(q.front()->left);
                    if (q.front()->right) q.push(q.front()->right);
                }
                // right depth reached!
                else {
                    q.front()->left = new TreeNode(val, q.front()->left, NULL);
                    q.front()->right = new TreeNode(val, NULL, q.front()->right);
                }
                q.pop();
            }
        }
        return root;        
    }
};