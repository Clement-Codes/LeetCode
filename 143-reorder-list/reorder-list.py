# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow, fast = head, head.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        second = slow.next
        
        

        temp = slow.next = None
        while second:
            t = second.next
            second.next = temp
            temp = second
            second = t

        first = head
        second = temp
        while first and second:
            fn, sn = first.next, second.next
            first.next = second
            second.next = fn
            second = sn
            first = fn

        