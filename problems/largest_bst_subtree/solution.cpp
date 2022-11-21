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
    // Function to check if given tree is a valid Binary Search Tree or not.
    bool isValidBST(TreeNode* root) {
        // An empty tree is a valid Binary Search Tree.
        if (!root) {
            return true;
        }

        // Find the max node in the left subtree of current node.
        int leftMax = findMax(root->left);

        // If the left subtree has a node greater than or equal to the current node,
        // then it is not a valid Binary Search Tree.
        if (leftMax >= root->val) {
            return false;
        }
        
        // Find the min node in the right subtree of current node.
        int rightMin = findMin(root->right);

        // If the right subtree has a value less than or equal to the current node,
        // then it is not a valid Binary Search Tree.
        if (rightMin <= root->val) {
            return false;
        }

        // If the left and right subtrees of current tree are also valid BST.
        // then the whole tree is a BST.
        if (isValidBST(root->left) && isValidBST(root->right)) {
            return true;
        }
        
        return false;
    }

    int findMax(TreeNode* root) {
        // Max node in a empty tree should be smaller than parent.
        if (!root) {
            return INT_MIN;
        }

        // Check the maximum node from the current node, left and right subtree of the current tree
        return max({ root->val, findMax(root->left), findMax(root->right) });
    }

    int findMin(TreeNode* root) {
        // Min node in a empty tree should be larger than parent.
        if (!root) {
            return INT_MAX;
        }

        // Check the minimum node from the current node, left and right subtree of the current tree
        return min({ root->val, findMin(root->left), findMin(root->right) });
    }
    
    int countNodes(TreeNode* root) {
        // Empty tree has 0 nodes.
        if (!root) {
            return 0;
        }
        
        // Add nodes in left and right subtree.
        // Add 1 and return total size.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        // If current subtree is a validBST, its children will have smaller size BST.
        if (isValidBST(root)) {
            return countNodes(root);
        }
        
        // Find BST in left and right subtrees of current nodes.
        return max(largestBSTSubtree(root->right), largestBSTSubtree(root->left));
    }
};