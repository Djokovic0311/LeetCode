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
    vector<int> tree;
    void preorder(TreeNode* root) {
        if(root) {
            if(root->left) preorder(root->left);
            tree.push_back(root->val);
            if(root->right) preorder(root->right);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> res;

        preorder(root);
        // for(int p : tree) cout << p <<' ';
        for(int q : queries) {
            int start = 0, end = 0;
            if(tree[0] > q) {
                start = -1;
            }
            if(tree[tree.size()-1] < q) {
                end = -1;
            }
            if(end != -1) {
                auto e = lower_bound(tree.begin(), tree.end(), q);
                end = *e;
            }
            if(end == q) start = end;
            else if(start != -1) {
                auto e = lower_bound(tree.begin(), tree.end(), q);
                start = *prev(e);
            }
            // cout << start << ' ' << end << endl;
            res.push_back({start,end});
        }
        return res;
    }
};