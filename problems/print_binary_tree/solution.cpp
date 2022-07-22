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
    int height(TreeNode* node)
    {
        if(node == NULL)
            return -1;
        int lh = height(node->left);
        int rh = height(node->right);
        
        return 1 + max(lh, rh);
    }
    
public:
    vector<vector<string>> printTree(TreeNode* root) 
    {
        
        int ht = height(root);
        int m = ht + 1;
        int n = pow(2, ht+1) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        
        //             node,       row, col
        queue<pair<TreeNode*, pair<int, int>>> que;
        que.push({root, {0, (int)((n-1)/2)}});
                
        while(!que.empty())
        {
            pair<TreeNode*, pair<int, int>> curr = que.front();
            que.pop();
            TreeNode* node = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            
            ans[row][col] = to_string(node->val);
            
            if(node->left != NULL)
            {
                que.push({node->left, {row+1, col - pow(2, ht-row-1)}});
            }
            if(node->right != NULL)
            {
                que.push({node->right, {row+1, col + pow(2, ht-row-1)}});
            }
        }
        return ans;
    }
};
