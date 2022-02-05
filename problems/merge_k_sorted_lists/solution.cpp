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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        map<int, int> nodes;

        for(int i = 0; i < lists.size(); ++i){
            auto node = lists[i];
            while(node){
                int temp = node->val;
                nodes[temp]++;
                node = node->next;
            }
        }
        
        ListNode dummyHead(0);
        ListNode* tail = &dummyHead;
        
        for(auto it: nodes){
            while(it.second != 0){
                ListNode* newNode= new ListNode(it.first);
                tail->next = newNode;
                tail = tail->next;
                it.second--;
            }
        }
        return dummyHead.next;        
    }
};