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
    struct comp{
        bool operator()(const pair<int, int>& x, const pair<int, int>& y){
            if(x.first == y.first)
                return x.second > y.second;
            return x.first < y.first;
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, comp>> mp;
        if(!root) return res;
        // node col row
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            mp[cur.second.first].push({cur.second.second, cur.first->val});
            if(cur.first->left) 
                q.push({cur.first->left, {cur.second.first - 1, cur.second.second - 1}});
            if(cur.first->right) 
                q.push({cur.first->right, {cur.second.first + 1, cur.second.second - 1}});
        }
        vector<int> temp;
        
        for(auto itr : mp){
            while(!itr.second.empty()){

                temp.push_back(itr.second.top().second);
                itr.second.pop();

            }
            res.push_back(temp);
            temp.clear();
        }
        
        return res;
    }
};
