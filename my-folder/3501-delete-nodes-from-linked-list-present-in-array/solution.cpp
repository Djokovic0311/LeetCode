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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> mp;
        for(int num : nums) {
            mp[num] = true;
        }
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* curr = head, *prev = dummyhead;
        while(curr) {
            if(mp[curr->val]) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummyhead->next;
    }
};
