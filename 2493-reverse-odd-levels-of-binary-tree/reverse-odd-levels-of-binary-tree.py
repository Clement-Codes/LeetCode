# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        queue = deque([root])
        i = 0
        while queue:
            n = len(queue)
            if i & 1:
                l, r = 0, n - 1
                while l < r:
                    queue[l].val, queue[r].val = queue[r].val, queue[l].val
                    l, r = l + 1, r - 1
            for _ in range(n):
                curr_l = queue.popleft()
                if curr_l.left:
                    queue.append(curr_l.left)
                if curr_l.right:
                    queue.append(curr_l.right)
            i += 1
        return root
