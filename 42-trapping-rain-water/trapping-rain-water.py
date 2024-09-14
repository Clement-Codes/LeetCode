class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        maxl = height[l]
        maxr = height[r]
        result = 0
        while l < r:
            if height[l] < height[r]:
                l += 1
                maxl = max(maxl, height[l])
                result += maxl - height[l]
            else:
                r -= 1
                maxr = max(maxr, height[r])
                result += maxr - height[r]         
        return result