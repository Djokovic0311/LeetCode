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
    int moves = 0;
    int traverse(TreeNode* root, int& moves) {
        if(!root) return 0;
        int l = traverse(root->left, moves);
        int r = traverse(root->right, moves);
        moves += abs(l) + abs(r);
        // cout << moves << endl;
        cout << root->val + l + r -1 << endl;
        return root->val + l + r -1;
    }
    int distributeCoins(TreeNode* root) {
        traverse(root, moves);
        return moves;
    }
};
