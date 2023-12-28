/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        if(root == nullptr) return "";

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur) {
                ans += to_string(cur->val) + " ";
                q.push(cur->left);
                q.push(cur->right);
            }
            else ans += "1010 ";
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int l = data.length();
        if(l == 0) return NULL;
        stringstream s(data);
        int cur_val;
        s>>cur_val;
        TreeNode* root = new TreeNode(cur_val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();    
            s>>cur_val;
            if(cur_val == 1010){
                cur->left = nullptr;
            }else {
                cur->left = new TreeNode(cur_val);
                q.push(cur->left);
            }
            s>>cur_val;
            if(cur_val == 1010){
                cur->right = nullptr;
            }else {
                cur->right = new TreeNode(cur_val);
                q.push(cur->right);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
