class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        count = [0, 0, 0]
        for i in s:
            count[ord(i) - ord('a')] += 1
        if min(count) < k:
            return -1
        result = float("inf")
        l = 0
        for r in range(len(s)):
            count[ord(s[r]) - ord('a')] -= 1

            if min(count) < k:
                count[ord(s[l]) - ord('a')] += 1
                l += 1
            
            result = min(result, len(s) - (r - l + 1))
            
        return result