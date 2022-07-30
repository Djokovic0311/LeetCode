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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                pair<TreeNode*, int> front = q.front();
                q.pop();
                
                if(front.first->left)
                {
                    pair<TreeNode*, int> newNode = {front.first->left, max(front.first->left->val, front.second)};
                    
                    if(newNode.second == newNode.first->val)
                        ans++;
                    q.push(newNode);
                }
                
                if(front.first->right)
                {
                    pair<TreeNode*, int> newNode = {front.first->right, max(front.first->right->val, front.second)};
                    
                    if(newNode.second == newNode.first->val)
                        ans++;
                    q.push(newNode);                
            }
        }
    }
        return ans;
    }
};
