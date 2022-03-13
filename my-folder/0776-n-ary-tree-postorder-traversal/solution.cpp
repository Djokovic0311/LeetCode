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
    vector<int> postorder(Node* root) {
        vector<int> res;
        postTraversal(root, res);
        return res;
    }

    void postTraversal(Node* root, vector<int>& ans){
        if(!root) return;                 // base condition
        // ans.push_back(root -> val);      
        for (auto& child : root -> children) postTraversal(child, ans); 
        ans.push_back(root -> val); 
    }
};
