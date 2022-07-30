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
    
    int pseudoPalindromicPaths (TreeNode* root) {
        queue<pair<TreeNode*, int>> q; //<node, mask>
        int ans=0;
        q.push({root, 1<<(root->val-1)});
        while(!q.empty()){
            auto [node, mask]=q.front();
            q.pop();
            if(!node->left && !node->right)
                ans+=__builtin_popcount(mask)<=1;// no. of set bits in mask
            if(node->left) q.push({node->left, mask^(1<<(node->left->val-1))});
            if(node->right) q.push({node->right, mask^(1<<(node->right->val-1))});
        }
        return ans;
    }

};
