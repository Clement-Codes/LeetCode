# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        #recursive BFS

        # if not root: return 0
        # return (1 + max(self.maxDepth(root.left), self.maxDepth(root.right)))
        
        #iterative BFS
        if not root: return 0
        queue = deque([root])
        result = 0

        while queue:
            for i in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            result += 1
        
        return result