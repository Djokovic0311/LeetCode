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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2,0);
        int count = 1;
        ListNode* prev = head, *cur = head->next;
        int mx = 0, mi = INT_MAX;
        int first = -1, before = 0;
        while(cur->next) {
            if((cur->val > prev->val && cur->val > cur->next->val) || (cur->val < prev->val && cur->val < cur->next->val)) {
                cout << before << endl;
                if(first == -1) {
                    first = count;
                }
                if(before != 0) {
                    mi = min(mi, count-before);
                    before = count;
                } else {
                    before = count;
                }
                mx = count - first;

            }
            prev = cur;
            cur = cur->next;
            count++;
        }
        if(mi == INT_MAX) mi = -1;
        if(mx == 0) mx = -1;
        return {mi, mx};
    }
};
