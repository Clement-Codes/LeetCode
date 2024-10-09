class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key = lambda x: x[0])
        for i in range(1, len(intervals)):
            a = intervals[i - 1][1]
            b = intervals[i][0]
            if a > b:
                return False
        return True
