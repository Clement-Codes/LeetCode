class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr) - 1
        r = n
        while r > 0 and arr[r - 1] <= arr[r]:
            r -= 1
        res = r
        
        l = 0
        while l < n  and arr[l] <= arr[l + 1]:
            l += 1
        
        res = min(res, n - l)

        l = 0
        r = n

        while l < r:
            while r <= n and l + 1 < r and arr[r - 1] <= arr[r] and arr[l] <= arr[r]:
                r -= 1
            
            while r <= n  and arr[l] > arr[r]:
                r += 1

            res = min(res, r - l - 1)

            if arr[l] > arr[l + 1]:
                break

            l += 1
            
            
        return res