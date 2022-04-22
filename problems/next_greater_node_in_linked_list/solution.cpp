/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, stk;
        if(head == NULL) return res;
        for(auto node = head; node; node = node->next) {
            while(stk.size() && res[stk.back()]<node->val) {
                res[stk.back()] = node->val;
                stk.pop_back();
            }
            stk.push_back(res.size());
            res.push_back(node->val);
        }
        for (int i: stk) res[i] = 0;
        return res;
    }
};