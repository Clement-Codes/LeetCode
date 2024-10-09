class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x : x[0])
        result = 0
        last = intervals[0][1]
        for i in intervals[1:]:
            if last <= i[0]:
                last = i[1]
            else:
                last = min(last, i[1])
                result += 1 
        return result