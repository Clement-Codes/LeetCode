# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = deque([root])
        level = []

        while q:
            s = 0
            for _ in range(len(q)):
                temp = q.popleft()
                if temp.left:
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
                s += temp.val
            level.append(s)

        q = deque([(root, root.val)])
        l = 0
        while q:
            for _ in range(len(q)):
                temp, val = q.popleft()
                temp.val = level[l] - val
                sibling = 0
                if temp.left:
                    sibling += temp.left.val
                if temp.right:
                    sibling += temp.right.val
                if temp.left:
                    q.append((temp.left, sibling))
                if temp.right:
                    q.append((temp.right, sibling))
            l += 1

        return root