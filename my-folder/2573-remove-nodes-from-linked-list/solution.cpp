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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* tmp = head;
        
        while(tmp) {
                while(!stk.empty() && stk.top()->val < tmp->val) {
                    stk.pop();
                }
            if(stk.empty() || stk.top()->val >= tmp->val) {
                stk.push(tmp);
            }

            tmp = tmp->next;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = NULL;
        while(!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            p->next = dummy->next;
            dummy->next = p;
        }
        return dummy->next;
    }
};

