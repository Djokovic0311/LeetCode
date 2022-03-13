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
    void dfs(TreeNode* root,set<int> &s){                                            
       if(root==NULL)
            return;
        dfs(root->left,s);
        s.insert(root->val);
        dfs(root->right,s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> tmp;
        dfs(root,tmp);
    if(tmp.size()==1)
        return -1;
    auto it=tmp.begin();
    it++;
    return *it;

    }
};
