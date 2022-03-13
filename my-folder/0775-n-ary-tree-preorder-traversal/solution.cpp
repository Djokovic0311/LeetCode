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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preTraversal(root, ans);
        return ans;
    }
    void preTraversal(Node* root, vector<int>& ans){
        if(!root) return;                 
        ans.push_back(root -> val);       // First push the root node,
        for (auto& child : root -> children) preTraversal(child, ans);  
    }
};
