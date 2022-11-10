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
        queue<pair<TreeNode*,int>> q;
        if(!root) return res;
        q.push(make_pair(root,1));
        int level = 1;
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i < n; i++) {
                auto [node, l] = q.front();
                q.pop(); 
                tmp.push_back(node->val);
                if(node->left != nullptr) {
                    q.push(make_pair(node->left,l+1));
                }
                if(node->right) {
                    q.push(make_pair(node->right,l+1));
                }
                    
            }
            if(level % 2 == 1)
                res.push_back(tmp);
            else {
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }
            level++;

        }
        return res;
    }
};
