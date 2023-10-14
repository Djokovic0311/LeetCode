/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;

        // If this node is already cloned, return the cloned version
        if (map.count(root)) return map[root];

        Node* clone = new Node(root->val);
        map[root] = clone;

        // Recursively clone children
        for (Node* child : root->children) {
            clone->children.push_back(cloneTree(child));
        }

        return clone;        
    }
};
