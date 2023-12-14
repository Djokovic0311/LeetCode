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
    map<int, vector<pair<int,int>>> mp;
    int minColumn = 0, maxColumn = 0;
    void dfs(TreeNode* node, int row, int col) {
        if(!node) {
            return;
        }

        mp[col].push_back(make_pair(row, node->val));
        minColumn = min(minColumn, col);
        maxColumn = max(maxColumn, col);
        dfs(node->left, row+1, col-1);
        dfs(node->right, row+1, col+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        dfs(root, 0, 0);
        for(int i = minColumn; i <= maxColumn; i++) {
            sort(mp[i].begin(), mp[i].end(), [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.first < b.first;
            }
            );
            vector<int> sortedColumn;
            for(auto p : mp[i]) {
                sortedColumn.push_back(p.second);
            }

            res.push_back(sortedColumn);
        }

        return res;
    }
};
