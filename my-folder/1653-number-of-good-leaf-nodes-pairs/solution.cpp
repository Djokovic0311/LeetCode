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
    int ans = 0;
    vector<int> findLeafDis(TreeNode* root, int distance) {
        if(!root) return {0};
        if(!root->left && !root->right) {
            return {1};
        }
        vector<int> left = findLeafDis(root->right, distance);
        vector<int> right = findLeafDis(root->left, distance);
        for(int l : left) {
            
            for(int r : right) {
                if(l > 0 && r > 0 && r+l <= distance)
                    ans++;
            }            
        }
        vector<int> leaves;
        for(int l : left) {
            if(l > 0 && l < distance)
                leaves.push_back(l+1);
        }
        for(int r : right) {
            if(r > 0 && r < distance)
                leaves.push_back(r+1);
        }

        return leaves;
    }
    int countPairs(TreeNode* root, int distance) {
        findLeafDis(root, distance);
        return ans;
    }
};
