# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        queue = collections.deque()
        queue.append(root)
        while queue:
            
            l = len(queue)
            rightMost = None
            for i in range(l):
                node = queue.popleft()
                if node:
                    rightMost = node
                    print(node.val)
                    queue.append(node.left)
                    queue.append(node.right)
            if rightMost:
                result.append(rightMost.val)
        return result