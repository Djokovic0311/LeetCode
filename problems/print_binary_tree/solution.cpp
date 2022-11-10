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
    int height(TreeNode* root) {
        if(!root) return -1;
        int l = height(root->left) +1;
        int r = height(root->right) +1;
        return max(l,r);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int ht = height(root);
        int m = ht + 1;
        int n = pow(2, ht+1) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));    
        queue<pair<TreeNode*, pair<int,int>>> q;
        res[0][(n-1)/2] = to_string(root->val);
        q.push(make_pair(root,make_pair(0,(n-1)/2)));
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            int r = tmp.second.first, c = tmp.second.second;
            TreeNode* node = tmp.first;
            if(node->left) {
                res[r+1][c-pow(2,ht-r-1)] = to_string(node->left->val);
                q.push(make_pair(node->left,make_pair(r+1,c-pow(2,ht-r-1))));
            }
                
            if(node->right) {
                res[r+1][c+pow(2,ht-r-1)] = to_string(node->right->val);
                q.push(make_pair(node->right,make_pair(r+1,c+pow(2,ht-r-1))));
            }
            
        }

        return res;
    }
};