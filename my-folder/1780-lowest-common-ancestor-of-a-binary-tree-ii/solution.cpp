/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> mp;
        mp[root] = NULL;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()) {
		TreeNode* tmpNode = qu.front();
                qu.pop();
                if(tmpNode->left) {
        mp[tmpNode->left] = tmpNode;
        qu.push(tmpNode->left);
        }
        if(tmpNode->right) {
            mp[tmpNode->right] = tmpNode;
            qu.push(tmpNode->right);
        }
        }

        unordered_set<TreeNode*> st;
        while(p) {
            st.insert(p);
            p = mp[p];
        }

        while(q) {
            if(st.count(q)) {
                return q;
            }
            q = mp[q];
        }

        return NULL;        
    }
};
