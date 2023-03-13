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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        int res = 0;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout << slow->val;
        ListNode* nxt = slow->next, *prev = NULL, * present = slow;
        slow = head;
        while(present) {
            present->next = prev;
            prev = present;
            present = nxt;
            if(nxt != nullptr) nxt = nxt->next;
        }

        while(prev != slow && prev && slow) {
            res = max(res, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        return res;
    }
};
