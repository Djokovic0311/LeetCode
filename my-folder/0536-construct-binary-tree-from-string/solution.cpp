/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        return str2treeInterval(s, 0).first;
    }
    pair<int,int> getNumber(string s, int index) {
        int num = 0;
        bool neg = false;
        if(s[index] == '-') neg = true, index++;
        while(index < s.length() && isdigit(s[index])) {
            // cout << num << " " << index << endl;
            num = num * 10 + s[index] - '0';
            index++;
        }
        // cout << num << " " << index << endl;
        return neg ? make_pair(-num, index) :  make_pair(num, index) ;
    }
    pair<TreeNode*, int> str2treeInterval(string s, int index) {
        if(index == s.length()) return {NULL, index};
        pair<int, int> parsedNumber = getNumber(s, index);
        // cout << parsedNumber.first << " " << parsedNumber.second << endl;
        TreeNode* root = new TreeNode(parsedNumber.first);
        index = parsedNumber.second;
        pair<TreeNode*, int> data;
        if(index < s.length() && s[index] == '(') {
            // cout << index + 1 << endl;
            data = str2treeInterval(s, index+1);
            root->left = data.first;
            index = data.second;
        }
        if(root->left && index < s.length() && s[index] == '(') {
            data = str2treeInterval(s, index+1);
            root->right = data.first;
            index = data.second;
        }

        return {root, index < s.length() && s[index] == ')' ? index+1 : index};
    }
};
