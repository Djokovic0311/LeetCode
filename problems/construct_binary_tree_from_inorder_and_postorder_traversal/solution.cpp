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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int> in(inorder), post(postorder);
        return postdfs(in, post, (TreeNode *)NULL);
    }

    TreeNode * postdfs(vector<int> & in, vector<int> & post, TreeNode * stop) {
        if ( post.empty() || (stop && in.back() == stop->val) ) {
            return NULL;
        }
        TreeNode * root = new TreeNode(post.back());
        post.pop_back();
        root->right = postdfs(in, post, root);
        in.pop_back();
        root->left = postdfs(in, post, stop);
        return root;
    }
};