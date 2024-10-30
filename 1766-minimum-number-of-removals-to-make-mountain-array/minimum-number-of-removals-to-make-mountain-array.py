class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        N = len(nums)
        pre = [1] * N
        
        for i in range(1, N):
            for j in range(i):
                if nums[i] > nums[j]:
                    pre[i] = max(pre[i], 1 + pre[j])

        pos = [1] * N

        for i in range(N-1, 0, -1):
            for j in range(i + 1, N):
                if nums[i] > nums[j]:
                    pos[i] = max(pos[i], 1 + pos[j])

        result = N
        for i in range(1, N-1):
            if min(pos[i], pre[i]) != 1:
                result = min(result, N - pos[i] - pre[i] + 1)

        return result