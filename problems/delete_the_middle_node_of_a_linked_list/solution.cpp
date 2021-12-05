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
  if (head->next == NULL || head == NULL)

    return NULL;

  if (head->next->next == NULL){
      head->next = NULL;
      return head;
  }


  ListNode* fast = head;

  ListNode* slow = head;

  ListNode* pre = NULL;

  /*

  head  1    2    3    4    5

  pre  slow  fast

  */

  //1个节点

  if (head->next->next == NULL)

    return head->next;

  while (fast->next != NULL && fast->next->next != NULL)

  {

    pre = slow;

    fast = fast->next->next;

    slow = slow->next;

  }

  //此时fast已到终点，slow为中间节点，pre为中间节点前一个节点
  if(fast->next != NULL){
      pre = slow;
      slow = slow->next;
  }
  pre->next = slow->next;
  return head;
    }
};