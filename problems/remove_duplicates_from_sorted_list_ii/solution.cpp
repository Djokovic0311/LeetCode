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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *prev = NULL, *cur = head, *next = cur->next;
        while(next) {
            if(next->val == cur->val) {
                while(next != NULL && cur->val == next->val)
                    next = next->next;
                if(!prev) 
                    head=next;
                else
                    prev->next = next;
            }
            else
            {
                prev=cur;
            }
            
            cur=next;
            if(next)
                next=cur->next;
        }
        return head;
    }
};