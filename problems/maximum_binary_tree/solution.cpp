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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // Base Condition
        if (nums.size() == 0) {
            return nullptr;
        }
        
        // Induction
        int maxVal = *max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(maxVal);
        int maxValIdx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxVal) {
                maxValIdx = i;
                break;
            }
        }
                
        vector<int> prefix(nums.begin(), nums.begin() + maxValIdx);
        vector<int> suffix(nums.begin() + maxValIdx + 1, nums.end());
                
        // Hypothesis
        root->left = constructMaximumBinaryTree(prefix);
        root->right = constructMaximumBinaryTree(suffix);
        
        return root;     
    }
};