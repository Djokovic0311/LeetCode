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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        if(root == NULL) return res;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> order;
            for(int i = 0; i < sz; i++) {
                TreeNode* head = q.front();
                order.push_back(head->val);
                if(head->left != NULL)
                    q.push(head->left);
                if(head->right != NULL)
                    q.push(head->right);
                q.pop();
            }
            res.push_back(order);
        }
        return res;
    }
};