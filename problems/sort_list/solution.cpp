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
    ListNode* sortList(ListNode* head) {
        vector<pair<int, ListNode*>> v;
        if(!head || !head->next) return head;
        while(head) {
            v.push_back(make_pair(head->val, head));
            head = head->next;
        }
        sort(v.begin(), v.end());
        cout << v.size();
        ListNode* dummy = new ListNode(-1);
        ListNode* h = dummy;
        // dummy->next = h
        for(auto p : v) {
            
            h->next = p.second;
            
            h = h->next;
            cout << h->val << endl;
        }
        h->next = NULL;
        return dummy->next;
    }
};