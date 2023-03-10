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
    int len = 0;
    vector<int> nodes;
    Solution(ListNode* head) {
        ListNode* tmp = head;

        while(tmp) {
            len++;
            nodes.push_back(tmp->val);
            tmp = tmp->next;
        }
    }
    
    int getRandom() {
        return nodes[rand()%len];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
