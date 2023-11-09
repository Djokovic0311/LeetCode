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
    Node* flipBinaryTree(Node* root, Node* leaf) 
    {      
        for(Node* c{leaf}, *n{}; c; )
        {
            auto p = c->parent;
            if(c->left==n or p) swap(c->parent, c->left );
            if(c->right==n)     swap(c->parent, c->right);
            n = exchange(c, p);
        }   
        return leaf;
    }

};
