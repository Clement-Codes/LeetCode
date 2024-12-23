# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        def count_swap(nums):
            result = 0
            n = len(nums)
            sorted_nums = sorted(nums)
            idx_nums = {v: i for i, v in enumerate(nums)}
            for i in range(n):
                if sorted_nums[i] != nums[i]:
                    result += 1
                    j = idx_nums[sorted_nums[i]]
                    nums[i], nums[j] = nums[j], nums[i]
                    idx_nums[nums[i]] = i
                    idx_nums[nums[j]] = j
            return result

        q = deque([root])
        result = 0
        while q:
            n = len(q)
            nums = [i.val for i in q]
            for _ in range(n):
                temp = q.popleft()
                if temp.left:
                    q.append(temp.left)
                if temp.right:
                    q.append(temp.right)
            result += count_swap(nums)
        return result