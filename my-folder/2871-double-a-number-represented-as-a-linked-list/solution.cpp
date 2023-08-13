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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }


    ListNode* doubleIt(ListNode* head) {
        if (!head) return nullptr;

        head = reverseList(head);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head, *prev = dummy;
        int carry = 0;

        while (curr || carry) {
            int sum = carry;
            if (curr) {
                sum += 2 * curr->val;
                curr = curr->next;
            }
            prev->next = new ListNode(sum % 10);
            prev = prev->next;
            carry = sum / 10;
        }

        return reverseList(dummy->next);
    }
};
