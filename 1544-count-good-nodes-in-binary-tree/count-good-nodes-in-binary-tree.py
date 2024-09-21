# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        return self.dfsGoodNodes(root, root.val)

    def dfsGoodNodes(self, node: TreeNode, maxValue: int) -> int:
        if not node: return 0
        result = 1 if node.val >= maxValue else 0
        maxValue = max(node.val, maxValue)
        result += self.dfsGoodNodes(node.left, maxValue) + self.dfsGoodNodes(node.right, maxValue)
        return result