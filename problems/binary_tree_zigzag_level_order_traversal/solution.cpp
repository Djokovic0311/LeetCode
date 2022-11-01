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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)   return res;
        vector<int>row;
        queue<TreeNode*>q;
        int x=0;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode*root=q.front();
                q.pop();
                row.push_back(root->val);
                if(root->left!=NULL)
                    q.push(root->left);
                if(root->right!=NULL)
                    q.push(root->right);
            }
            if(x%2==0)
                res.push_back(row);
            else
            {
                reverse(row.begin(),row.end());
                res.push_back(row);
            }
            row.clear();
            x+=1;
        }
        return res;
    }
};