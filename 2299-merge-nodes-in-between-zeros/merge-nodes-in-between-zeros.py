# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode()
        t = result
        temp = head.next
        curr = 0
        while temp:
            if temp.val == 0:
                result.val = curr
                curr = 0
                if temp.next:
                    temp2 = ListNode()
                    result.next = temp2
                    result = temp2
            else:
                curr += temp.val
            temp = temp.next
                
        return t
        