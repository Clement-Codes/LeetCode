# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        queue = deque()
        queue.append((0, root))
        while queue:
            n = len(queue)
            i = 0
            temp = queue.copy()
            while i != n:
                level_l, curr_l = queue.popleft()
                if level_l % 2 != 0 and i < n/2:
                    level_r, curr_r = temp.pop()
                    curr_l.val, curr_r.val = curr_r.val, curr_l.val
                if curr_l.left:
                    queue.append((level_l + 1, curr_l.left))
                if curr_l.right:
                    queue.append((level_l + 1, curr_l.right))
                i += 1
        return root
