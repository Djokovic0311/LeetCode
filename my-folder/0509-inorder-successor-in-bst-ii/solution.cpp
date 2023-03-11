/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(!node) return NULL;
        if(node->right) {
            Node* tmp = node->right;
            while(tmp->left) {
                tmp = tmp->left;
            }
            return tmp;
        }


        while (node->parent && node->parent->right == node) {
            node = node->parent;
        }
        node = node->parent;

        return node;
    }
};
