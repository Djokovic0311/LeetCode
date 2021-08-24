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
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i = 0, j = vec.size() - 1;
        while(i < j){
            if(vec[i] + vec[j] == k) return true;
            else if(vec[i] + vec[j] < k) i++;
            else j--;
        }
        return false;
    }
private:
    vector<int> vec;
    
};
