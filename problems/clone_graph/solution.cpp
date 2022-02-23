/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* nodes[101] = {0};
    void createNode(Node *originalNode) {
		if (!nodes[originalNode->val]) {
            nodes[originalNode->val] = new Node(originalNode->val);
        }
        for (auto n: originalNode->neighbors) {
            if (!nodes[n->val]) createNode(n);
            nodes[originalNode->val]->neighbors.push_back(nodes[n->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (node) createNode(node);
        return nodes[1];
    }
};