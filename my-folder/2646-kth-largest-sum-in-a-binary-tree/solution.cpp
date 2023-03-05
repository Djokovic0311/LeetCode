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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long res = -1;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        unordered_map<int, long long> levelSum; // level -> sum
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum[level] += (long long)node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            level++;
        }

        // Sort the level sums in descending order and return the kth largest level sum
        vector<long long> sums;
        for (auto p : levelSum) {
            sums.push_back(p.second);
        }
        sort(sums.rbegin(), sums.rend());
        if (k > sums.size()) {
            return -1;
        }
        return sums[k - 1];

    }
};
