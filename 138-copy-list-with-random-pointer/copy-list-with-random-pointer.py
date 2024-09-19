"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        old = {None: None}
        cur = head
        while cur:
            old[cur] = Node(cur.val)
            cur = cur.next
        
        cur = head
        while cur:
            old[cur].next = old[cur.next] 
            old[cur].random = old[cur.random]
            cur = cur.next

        cur = head
        return old[cur]
