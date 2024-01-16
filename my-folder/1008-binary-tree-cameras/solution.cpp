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
    int total = 0;
    int minCameraCover(TreeNode* root) {
        int val =  postorder(root);
        if(val==1) total++;//if val == 1 root node requires monitoring so we add a camera there.

        return total;
    }
    int postorder(TreeNode* root){
        if(!root) return 3;

        int left = postorder(root->left);
        int right  = postorder(root->right);

        if(left==1||right==1){
            total++;
            return 2;
        }
        if(left==3&&right==3){
            return 1;
        }
        if(left==2||right==2){
            return 3;
        }
        return 0;

    }
};
