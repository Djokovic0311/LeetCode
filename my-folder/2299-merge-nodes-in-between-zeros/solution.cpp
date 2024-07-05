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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        while(head) {
            int sum = 0;
            head = head->next;
            while(head && head->val != 0) {
                sum += head->val;
                head = head->next;
            }
            cout << sum << endl;
            if(sum != 0) {
                pre->next = new ListNode(sum);
                pre = pre->next;
            }

            
        }
        return dummy->next;
    }
};
