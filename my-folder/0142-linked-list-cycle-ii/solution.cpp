/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head) {
            if (seen.find(head) != end(seen)) return head;
            seen.insert(head);
            head = head->next;
        }
        return NULL;        
    }
};
