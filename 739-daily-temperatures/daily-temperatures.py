class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result = [0] * len(temperatures)
        stack = []
        for i, j in enumerate(temperatures):
            while stack and j > stack[-1][1]:
                k, l = stack.pop()
                result[k] = i - k
            stack.append((i, j))
        return result