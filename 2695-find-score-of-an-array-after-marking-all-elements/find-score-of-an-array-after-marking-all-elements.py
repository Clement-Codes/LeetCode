class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        heap = []
        visited = [False] * n
        for i in range(n):
            heapq.heappush(heap, (nums[i], i))
        result = 0
        while heap:
            temp = heapq.heappop(heap)
            if visited[temp[1]]:
                continue
            visited[temp[1]] = True
            if temp[1] - 1 >= 0:
                visited[temp[1] - 1] = True
            if temp[1] + 1 < n:
                visited[temp[1] + 1] = True
            result += temp[0]
        return result
