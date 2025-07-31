class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        curr = set()
        prev = set()
        result = set()
        for i in arr:
            curr.clear()
            curr.add(i)
            for j in prev:
                curr.add(i | j)
            result.update(curr)
            prev = curr.copy()
        return len(result)