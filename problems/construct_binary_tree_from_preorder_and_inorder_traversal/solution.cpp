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
    int id = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, inorder, 0, preorder.size()-1);
    }
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if(start > end) return NULL;
        TreeNode* node = new TreeNode(preorder[id++]);
        int pos = 0;
        for(int i = start; i <= end; i++) {
            if(inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = create(preorder, inorder, start, pos-1);
        node->right = create(preorder, inorder, pos+1, end);
        return node;
    }
};