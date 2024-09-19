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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        int carry = 0;
        while(l1!=null || l2!=null || carry!=0){
            int val1 = l1!=null ? l1.val : 0;
            int val2 = l2!=null ? l2.val : 0;
            int add = val1 + val2 + carry;
            int val = add % 10;
            carry = (int)Math.floor(add/10.0);

            ListNode temp = new ListNode(val);
            curr.next = temp;
            curr = curr.next;
            
            l1 = l1!=null ? l1.next : null;
            l2 = l2!=null ? l2.next : null;

        }

        return dummy.next;   
    }
}