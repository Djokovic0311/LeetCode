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
    ListNode* reverseKGroup(ListNode* head, int k) {
 		//edge cases
        if (head == NULL || k ==0 ||k==1)return head;
		// Store all node values in a vector.
        vector<int> v;
        ListNode* p = head;
        while(p){
            v.push_back(p->val);
            p = p->next;
        }
        int n = v.size();
		// r is how many sub groups are to be reversed; 
        int r = n/k;
        int q = 0;
		// Apply operations on the vector i.e, swap values in a loop. 
        while(r--){
            int i = k*q;
            int j = (k)*(q+1) - 1;
            while(i<j){
                swap(v[i++], v[j--]);
            }
            q++;
        }
		// Make a new LinkedList by the processed vector and return it.
        ListNode* a = new ListNode(v[0]);
        ListNode* b = a;
        for(int i =1; i<v.size(); i++){
            b->next = new ListNode(v[i]);
            b = b->next;
        }
        return a;
    }       
    
};