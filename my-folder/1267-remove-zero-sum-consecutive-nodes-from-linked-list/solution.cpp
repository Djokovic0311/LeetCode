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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        while (temp) {
            vec.push_back(temp->val); 
            temp = temp->next;
        }
        
        for (int start = 0; start < vec.size(); start++) {
            int sum = 0;
            for (int end = start; end < vec.size(); end++) {
                sum += vec[end]; 
                if (sum == 0) {
                    for (int i = start; i <= end; i++) {
                        vec[i] = 0; 
                    }
                    break;
                }
            }
        }
        
        ListNode alt(0); // dummy node is created so that we can make a linked list with values from the vector
        ListNode* a = &alt;
        for (int p = 0; p < vec.size(); p++) {
            if (vec[p] != 0) { 
                a->next = new ListNode(vec[p]);
                a = a->next;
            }
        }
        a->next = nullptr;
        return alt.next;

    }
};
