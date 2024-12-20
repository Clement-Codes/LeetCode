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
    public ListNode mergeNodes(ListNode head) {
        ListNode result = new ListNode();
        ListNode itterator = head.next;
        ListNode resultItterator = result;
        int val = 0;

        while (itterator != null){
            if (itterator.val == 0){
                resultItterator.val = val;
                if (itterator.next != null){
                    ListNode temp = new ListNode();
                    resultItterator.next = temp;
                    resultItterator = resultItterator.next;
                }
                val = 0;
            }
            else{
                val += itterator.val;
            }
            itterator = itterator.next;
        }
        return result; 
    }
}