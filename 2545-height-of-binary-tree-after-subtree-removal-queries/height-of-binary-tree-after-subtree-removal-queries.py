# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        levels = defaultdict(int)
        heights = defaultdict(int)
        largests = defaultdict(list)
        result = []

        def preprocessing(curr, level):
            if not curr:
                return 0
            height = 1 + max(preprocessing(curr.left, level + 1), preprocessing(curr.right, level + 1) ) 
            levels[curr.val] = level
            heights[curr.val] = height
            if not largests[level]:
                largests[level] = [0, 0]
            if height > largests[level][0]:
                largests[level][0], largests[level][1] = height, largests[level][0]
            elif height > largests[level][1]:
                largests[level][1] = height
            return height

        preprocessing(root, 0)
        
        for i in queries:
            temp_level = levels[i]
            temp_height = heights[i]
            result.append((largests[temp_level][1] if temp_height == largests[temp_level][0] else largests[temp_level][0])+ temp_level - 1)

        return result
        # result = []
        # def deepCopy(curr):
        #     if not curr: return None
        #     temp = TreeNode(curr.val)
        #     if curr.left:
        #         temp.left = deepCopy(curr.left)
        #     if curr.right:
        #         temp.right = deepCopy(curr.right)
        #     return temp              
            
        # def deleteDfs(curr, i):
        #     if curr.val == i:
        #         return None
        #     if curr.left:
        #         curr.left = deleteDfs(curr.left, i)
        #     if curr.right:
        #         curr.right = deleteDfs(curr.right, i)   
        #     return curr    

        # def height(curr):
        #     if not curr:
        #         return 0
        #     return max(1 + height(curr.left), 1 + height(curr.right))

        # for i in queries:
        #     curr = deepCopy(root)
        #     curr = deleteDfs(curr, i)
        #     queue = deque([curr])
        #     while queue:
        #         for _ in range(len(queue)):
        #             t = queue.popleft()
        #             if t.left:
        #                 queue.append(t.left)
        #             if t.right:
        #                 queue.append(t.right)
        #     result.append(height(curr) - 1)
        # return result
