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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res = "";
        serialize_helper(root, res);
        return res;
    }

    void serialize_helper(Node* root, string& s) {
        if(!root) return;
        s += " " + to_string(root->val) + " " + to_string(root->children.size());
        for(auto c : root->children) {
            serialize_helper(c, s);
        }
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.length() == 0) return NULL;
        queue<string> q;
        string s;
        for(int i = 1; i < data.length(); i++) {
            if(data[i] == ' ') {
                q.push(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        if(s.length()) q.push(s);

        return deserialize_helper(q);
    }

    Node* deserialize_helper(queue<string>& q) {
        Node* root = new Node(stoi(q.front()));
        q.pop();
        int numOfChildren = stoi(q.front());
        q.pop();
        for(int i = 0; i < numOfChildren; i++) {
            root->children.push_back(deserialize_helper(q));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
