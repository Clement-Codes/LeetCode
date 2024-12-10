class Solution:
    def maximumLength(self, s: str) -> int:
        memo = defaultdict(int)
        for i in range(len(s)):
            curr = []
            for j in range(i, len(s)):
                if not curr or curr[-1] == s[j]:
                    curr.append(s[j])
                    key = ''.join(curr)
                    memo[key] += 1
                else:
                    break
        result = 0
        for i, j in memo.items():
            if j >= 3 and len(i) > result:
                result = len(i)
        return result if result > 0 else -1