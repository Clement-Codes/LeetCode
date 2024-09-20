# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        tail = dummy

        while True:
            kth = self.getKthNode(tail, k)
            if not kth: break

            nextGroup = kth.next
            prev = kth.next
            curr = tail.next
            
            while curr != nextGroup:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
            
            temp = tail.next
            tail.next = prev
            tail = temp

        return dummy.next

    def getKthNode(self, node: Optional[ListNode], k: int) -> Optional[ListNode]:
        while node and k:
            node = node.next
            k -= 1
        return node