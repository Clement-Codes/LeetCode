class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        cache = {}
        for i, c in enumerate(s):
            cache[c] = i
        result = []
        curr = end = 0
        for i, c in enumerate(s):
            curr += 1
            end = max(end, cache[c])
            if i == end:
                result.append(curr)
                curr = 0
        return result
