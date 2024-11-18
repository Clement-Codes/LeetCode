class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        result = [0] * n
        l = 0
        s = 0
        for r in range(n + abs(k)):
            s += code[r % n]
            if r - l + 1 > abs(k):
                s -= code[l % n]
                l = (l + 1) % n
            
            if r - l + 1 == abs(k):
                if k > 0:
                    result[(l - 1) % n] = s
                elif k < 0:
                    result[(r + 1) % n] = s
        return result

        # n = len(code)
        # result = [0] * n
        # for i in range(n):
        #     if k > 0:
        #         for j in range(i+1, i + k + 1):
        #             result[i] += code[j % n]
        #     if k < 0:
        #         for j in range(i - 1, i - abs(k) -1, -1):
        #             result[i] += code[j % n]         
        # return result