class Solution:
    
    def findKthBit(self, n: int, k: int) -> str:
        invert = False
        length = 2**n - 1

        def helper(length, k, invert):
            if length == 1:
                return '0' if not invert  else '1'
            half = length // 2
            if k <= half:
                return helper(half, k, invert)
            elif k > half + 1:
                return helper(half, 1 + length - k, not invert)
            else:
                return '1' if not invert  else '0'

        return helper(length, k, invert)

        # cache = {}
        # def inverse(strs):
        #     result = ""
        #     for s in strs:
        #         if s == '0':
        #             result += '1'
        #         else:
        #             result += '0'
        #     return result

        # def dfs(i):
        #     if i in cache: return cache[i]
        #     if i == 1:
        #         return '0'

        #     cache[i] = dfs(i-1) + "1" + inverse(dfs(i-1))[::-1]
        #     return cache[i]

        # return dfs(n)[k - 1]