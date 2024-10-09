class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingDouble(a -> a[0]));
        for (int i = 1; i < intervals.length; i++)
        {
            int a = intervals[i - 1][1];
            int b = intervals[i][0];
            if (a > b) return false;
        }            
        return true;
    }
}