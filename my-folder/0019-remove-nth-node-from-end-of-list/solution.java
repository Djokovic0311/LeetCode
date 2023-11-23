/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        int l = 0;
        while(head != null) {
            l++;
            head = head.next;
        }
        ListNode curr = dummy.next;
        ListNode prev = dummy;
        while(l-- > n) {
            curr = curr.next;
            prev = prev.next;
        }
        prev.next = curr.next;
        

        return dummy.next;
    }
}
