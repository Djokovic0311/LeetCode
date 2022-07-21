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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) 
			return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            
            
            int mx = INT_MIN;
            for(int i = 0; i < sz; i++) {
                TreeNode* head = q.front();
                if(head->left != NULL) q.push(head->left);
                if(head->right != NULL) q.push(head->right);
                if(mx < head->val) mx = head->val;
                q.pop();
            }
            res.push_back(mx);
        }
        return res;
    }
};
