class Solution:
    
    def findKthBit(self, n: int, k: int) -> str:
        
        def helper(length, k):
            if length == 1:
                return '0'
            half = length // 2
            if k <= half:
                return helper(half, k)
            elif k > half + 1:
                res = helper(half, 1 + length - k)
                return '0' if res == '1' else '1'
            else:
                return '1'

        return helper(2**n - 1, k)
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