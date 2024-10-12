class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        starts = [i for i, _ in intervals]
        ends = [j for _, j in intervals]
        starts.sort()
        ends.sort()
        result = 0
        count = 0
        i = 0
        j = 0
        while i < len(intervals) and j < len(intervals):
            if starts[i] <= ends[j]:
                count += 1
                i += 1
            else:
                j += 1
                count -= 1
            result = max(result, count)
        return result