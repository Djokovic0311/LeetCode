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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> row;
            for(int i = 0; i < sz; i++) {
                Node* tmp = q.front();
                q.pop();
                for(auto c : tmp->children) {
                    q.push(c);
                }
                row.push_back(tmp->val);
            }
            res.push_back(row);
        }
        return res;
    }
};