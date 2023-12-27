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
    int res = 0;
    int height(Node* node) {
        if(node->children.size() == 0) return 0;
        int maxHeight1 = 0, maxHeight2 = 0;
        for(auto child : node->children) {
            int parentHeight = height(child)+1;
            if(parentHeight > maxHeight1) {
                maxHeight2 = maxHeight1;
                maxHeight1 = parentHeight;
            } else if (parentHeight >maxHeight2 ) {
                maxHeight2 = parentHeight;
            }
            res = max(res, maxHeight2 + maxHeight1);
        }

        return maxHeight1;
    }
    int diameter(Node* root) {
        height(root);
        return res;
    }
};
