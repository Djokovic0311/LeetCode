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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head, *slow = head;
       if (head == NULL) {
          return NULL;
       }
       if (head->next == NULL) {
          delete head;
          return NULL;
       }        
        while(fast!=NULL && fast->next!= NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* record = head;
        while(record->next!=slow && record->next != NULL) {
            record = record->next;
        }
        record->next = slow->next;
        // delete(slow);
        return head;
    }
};
