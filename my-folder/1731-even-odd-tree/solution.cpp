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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        bool res = true;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> lvl;
            for(int i = 0; i < sz; i++) {
                auto curr = q.front();
                q.pop();
                if(level % 2 == 0) {
                    if(curr->val % 2 == 1) {
                        if(lvl.empty() || curr->val > lvl.back())
                            lvl.push_back(curr->val);
                        else return false;
                    } else return false;
                } else {
                    if(curr->val % 2 == 0) {

                        if(lvl.empty() || curr->val < lvl.back())
                            lvl.push_back(curr->val);
                        else return false;
                    } else return false;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
            lvl.clear();
        }

        return true;
    }
};
