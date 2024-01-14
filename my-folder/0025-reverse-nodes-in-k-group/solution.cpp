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
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* new_head = nullptr;
        ListNode* ptr = head;

        while (k > 0) {
            ListNode* next_node = ptr->next;
            ptr->next = new_head;
            new_head = ptr;
            ptr = next_node;
            k--;
        }

        return new_head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* ptr = head;

        // First, check if there are at least k nodes left in the linked list.
        while (count < k && ptr != nullptr) {
            ptr = ptr->next;
            count++;
        }

        // If we have k nodes, then we reverse them.
        if (count == k) {
            ListNode* reversedHead = reverseLinkedList(head, k);
            head->next = reverseKGroup(ptr, k);
            return reversedHead;
        }

        return head;
    }
};
