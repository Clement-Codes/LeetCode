# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.result = 0
        self.dfsHeight(root)
        return self.result
    
    def dfsHeight(self, root:Optional):
        if not root: return 0
        
        left = self.dfsHeight(root.left)
        right = self.dfsHeight(root.right)

        self.result = max(self.result, left + right)

        return max(1 + left, 1 + right)