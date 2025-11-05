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
    Node* findRoot(vector<Node*> tree) {
        int n = tree.size();
        unordered_set<Node*> st;
        for(auto node: tree) {
            for(auto child : node->children) {
                st.insert(child);
            }
        }
        for(auto node: tree) {
            if(!st.count(node)) {
                return node;
            }
        }
        return nullptr;
    }
};
