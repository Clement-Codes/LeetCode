class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        result = [0] * n
        for i in range(n):
            if k > 0:
                for j in range(i+1, i + k + 1):
                    result[i] += code[j % n]
            if k < 0:
                for j in range(i - 1, i - abs(k) -1, -1):
                    result[i] += code[j % n]         
        return result