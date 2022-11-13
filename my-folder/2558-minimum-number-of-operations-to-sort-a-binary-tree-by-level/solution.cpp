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
    int getMinSwaps(vector<int> &nums){
    //排序
    vector<int> nums1(nums);
    sort(nums1.begin(),nums1.end());
    unordered_map<int,int> m;
    int len = nums.size();
    for (int i = 0; i < len; i++){
        m[nums1[i]] = i;//建立每个元素与其应放位置的映射关系
    }
    int loops = 0;//循环节个数
    vector<bool> flag(len,false);
    //找出循环节的个数
    for (int i = 0; i < len; i++){
        if (!flag[i]){//已经访问过的位置不再访问
            int j = i;
            while (!flag[j]){
                flag[j] = true;
                j = m[nums[j]];//原序列中j位置的元素在有序序列中的位置
            }
            loops++;
        }
    }
    return len - loops;
    }
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res += getMinSwaps(tmp);
        }
        return res;
    }   
};
