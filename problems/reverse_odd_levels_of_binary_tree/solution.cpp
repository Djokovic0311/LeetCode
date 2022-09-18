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
void levelOrderTraversal(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
 
    // create an empty queue and enqueue the root node
    queue<TreeNode*> queue;
    queue.push(root);
 
    // pointer to store the current node
    TreeNode* curr = nullptr;
 
    // loop till queue is empty
    while (queue.size())
    {
        // process each node in the queue and enqueue their
        // non-empty left and right child
        curr = queue.front();
        queue.pop();
 
        cout << curr->val << " ";
 
        if (curr->left) {
            queue.push(curr->left);
        }
 
        if (curr->right) {
            queue.push(curr->right);
        }
    }
}
 
// Iterative function to invert alternate levels of a perfect binary tree
// using level order traversal

    TreeNode* reverseOddLevels(TreeNode* root) {
            // base case: if the tree is empty
    if (root == nullptr) {
        return NULL;
    }
 
    // maintain a queue and enqueue the root node
    queue<TreeNode*> q;
    q.push(root);
 
    // to store current level information
    bool level = false;
 
    // maintain another queue to store nodes present at an odd level
    queue<TreeNode*> level_nodes;
 
    // maintain a stack to store node's data on an odd level
    stack<int> level_data;
 
    // loop till queue is empty
    while (!q.empty())
    {
        // get the size of the current level
        int n = q.size();
 
        // process all nodes present at the current level
        while (n--)
        {
            // dequeue front node
            TreeNode* curr = q.front();
            q.pop();
 
            // if the level is odd
            if (level)
            {
                // enqueue current node
                level_nodes.push(curr);
 
                // push the current node data into the stack
                level_data.push(curr->val);
            }
 
            // if the current node is the last node of the level
            if (n == 0)
            {
                // flip the level
                level = !level;
 
                // put elements present in the `level_data` into their correct
                // position using `level_nodes`
                while (!level_nodes.empty())
                {
                    TreeNode* front = level_nodes.front();
                    front->val = level_data.top();
 
                    level_nodes.pop();
                    level_data.pop();
                }
            }
 
            // enqueue left child of the current node
            if (curr->left) {
                q.push(curr->left);
            }
 
            // enqueue right child of the current node
            if (curr->right) {
                q.push(curr->right);
            }
        }
    }
        return root;
    }
};