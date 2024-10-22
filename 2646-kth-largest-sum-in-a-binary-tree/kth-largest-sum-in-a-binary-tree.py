# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        queue = deque([root])
        result = []

        while queue:
            s = 0
            for i in range(len(queue)):
                temp = queue.popleft()
                s += temp.val
                if temp.left:
                    queue.append(temp.left)
                if temp.right:
                    queue.append(temp.right)

            heapq.heappush(result, s)
            if len(result) > k:
                heapq.heappop(result)

        return -1 if len(result) < k else result[0]
        