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
    int maxLevelSum(TreeNode* root) {
        int mx = INT_MIN;
        int curlevel = 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            int cur = 0;
            for(int i = 0; i < sz; i++) {
                auto head = q.front();
                q.pop();
                cur += head->val;
                if(head->left) q.push(head->left);
                if(head->right) q.push(head->right);
                
            }
            level++;
            if(cur > mx) {
                curlevel = level;
                mx = cur;
            }
        }
        return curlevel;
    }
};
