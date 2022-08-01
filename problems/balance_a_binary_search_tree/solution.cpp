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
    vector<TreeNode*> bst;
    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root->left);
        bst.push_back(root);
        inorder(root->right);
    }
    TreeNode* buildTree(int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* root=bst[mid];
        root->left=buildTree(start,mid-1);
        root->right=buildTree(mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        inorder(root);
        int n=bst.size();
        root=buildTree(0,n-1);
        return root;        
    }
};