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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(root);
        int i = 0; 
        while(i < v.size() && v[i]) {
            // cout << i << endl;
            v.push_back(v[i]->left);
            v.push_back(v[i]->right);
            i++;
        }
        // 1 2 3 4 5 6 null null null null null null null
        // i = 6
        // 1 2 3 4 5 null 7 null null null null 
        // i = 5

    
        while (i < v.size() && !v[i])
            i++;
        return i == v.size();
    }
};
