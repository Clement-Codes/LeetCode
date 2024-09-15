class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        maxArea = 0
        for i, j in enumerate(heights):
            start = i
            while stack and j < stack[-1][1]:
                a, b = stack.pop()
                maxArea = max(maxArea, (i-a) * b)
                start = a
            stack.append((start, j))

        while stack:
            a, b = stack.pop()
            maxArea = max(maxArea, (len(heights)-a) * b)

        return maxArea