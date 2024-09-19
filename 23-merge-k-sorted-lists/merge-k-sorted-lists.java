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

import java.util.Vector;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;

        while(lists.length>1){
            Vector<ListNode> mergedLists = new Vector<ListNode>();
            for(int i = 0; i < lists.length; i = i+2){
                ListNode l1 = lists[i];
                ListNode l2 = i + 1 < lists.length ? lists[i + 1] : null;
                mergedLists.add(mergeSort(l1, l2)); 
            }
            lists = mergedLists.toArray(new ListNode[mergedLists.size()]);
        }

        return lists[0];
    }

    public ListNode mergeSort(ListNode l1, ListNode l2){
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while(l1!=null && l2!=null){
            if(l1.val <= l2.val){
                tail.next = l1;
                l1 = l1.next;
            }
            else{
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }

        if (l1!=null){
            tail.next = l1;
        }
        if (l2!=null){
            tail.next = l2;
        }

        return dummy.next;
    }
}