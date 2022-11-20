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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root,0});
        int width = 0;

        while(!q.empty()) {
            int sz = q.size();
            unsigned long long int left = q.front().second, right = 0;
            while(sz-- > 0) {
                pair<TreeNode*, unsigned long long int> rNode = q.front();
                q.pop();
                right = rNode.second;
                if(rNode.first->left) {
                    q.push({rNode.first->left, 2 * right + 1});
                }
                if(rNode.first->right) {
                    q.push({rNode.first->right, 2 * right + 2});
                }
                
            }
            width = max(width, int(right - left + 1));
        }
        return width;
    }
};
